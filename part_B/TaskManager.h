#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Task.h"
#include "TaskQueue.h"
#include "TaskStack.h"
#include "TaskTimeline.h"

#include <string>

class TaskManager {

    private:
    TaskQueue inbox_;
    TaskTimeline timeline_;
    TaskStack undoHistory_;

public:
    TaskManager(){}
    ~TaskManager(){}

    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    // Route an incoming task based on priority:
    // 0: enqueue to inbox
    // 1: insertFirst to inbox
    // 2: bypass inbox and insertFirst to timeline
    void receiveTask(const Task& task){
        if(task.priority == 0){
            inbox_.enqueue(task);
        }
        else if(task.priority == 1){
            inbox_.insertFirst(task);
        }
        else if(task.priority == 2){
            timeline_.insertFirst(task);
        }
    }
    // Dequeue the next inbox task and append it to the timeline.
    // Returns the processed taskId, or -1 if the inbox is empty.
    int processNextTask(){
        if (inbox_.isEmpty()) return -1;
        Task t = inbox_.dequeue();
        timeline_.insertLast(t);
        return t.taskId;
    }
    // Remove taskId from the timeline and push it onto the undo stack.
    // Returns taskId on success, or -1 if it is not on the timeline.
    int deleteTask(int taskId){
        if(timeline_.find(taskId) == nullptr){
            return -1;
        }
        else{
            Task* t = timeline_.find(taskId);
            undoHistory_.push(*t);
            timeline_.remove(taskId);
            return taskId;
        }
    }
    // Remove taskId from the timeline permanently (no undo).
    // Returns taskId on success, or -1 if it is not on the timeline.
    int completeTask(int taskId){
        if(timeline_.remove(taskId)){
            return taskId;
        }
        else{
            return -1;
        }
    }
    // Remove the task at the front of the timeline permanently (no undo).
    // Returns the front taskId on success, or -1 if the timeline is empty.
    int completeTask(){
        if(timeline_.isEmpty()){
            return -1;
        }
        else{
            Task t = timeline_.removeFirst();
            return t.taskId;
        }
    }
    // Pop the undo stack and append the restored task to the timeline.
    // Returns the restored taskId, or -1 if the undo stack is empty.
    int undo(){
        if(undoHistory_.isEmpty()){
            return -1;
        }
        else{
            Task t = undoHistory_.pop();
            timeline_.insertLast(t);
            return t.taskId;
        }
    }
    // Return the timeline toString() representation, e.g. "[1, 2, 3]".
    std::string printTimeline() const{
        return timeline_.toString();
    }
};

#endif // TASK_MANAGER_H
