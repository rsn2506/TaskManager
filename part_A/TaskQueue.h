#pragma once
#include <iostream>
#include "EmptyQueueException.h"
#include "Task.h"
using namespace std;

class QueueNode{ // 

  private:
    Task task;
    QueueNode* next;

  public:

//constructors  
    QueueNode():task(),next(nullptr){}
    QueueNode(Task t, QueueNode* t_p = nullptr):task(t),next(t_p){}

//getters
  const Task& getTask() const{
    return task;
  }

  QueueNode* getNext() const{
    return next;
  }

//setters
  void setTask(const Task& newTask) {
    task = newTask;
  }

  //next is declared as a QueueNode pointer. 
  //But in setNext if it is set to const QueueNode pointer, c++ wont allow const beside param
  void setNext(QueueNode* t_n) {
    next = t_n;
  }

};

class TaskQueue {
  private:
    QueueNode* head;
    QueueNode* tail;
    int cursize;

  public:

//constructors
//order of of the constructor calls should be same as the order of declaration of the member variables in the class
    TaskQueue():head(nullptr),tail(nullptr),cursize(0){}
    ~TaskQueue(){
      while(head!=nullptr){
        QueueNode* a = head->getNext();
        delete head;
        head = a;
      }
      cursize = 0;
    }
  void enqueue(const Task& task){
    QueueNode* n1 = new QueueNode(task);
    if(isEmpty()){
      head = n1;
      tail = n1;
      cursize = cursize+1;
      return;
    }
    tail->setNext(n1);
    tail = n1;
    cursize = cursize+1;
  } // append
  void insertFirst(const Task& task){
    QueueNode* n1 = new QueueNode(task);
    if(isEmpty()){
      head = n1;
      tail = n1;
      cursize = cursize+1;
      return;
    }
    n1->setNext(head);
    head = n1;
    cursize = cursize+1;
  } // prepend
  Task dequeue(){
    if(isEmpty()){
		  throw EmptyQueueException();
	  }
	  else{
		  QueueNode* n2 = head->getNext();
		  Task t = head->getTask();
		  delete head;
		  cursize = cursize - 1;
		  head = n2;
		  if(head == nullptr){
		    tail = nullptr;
		  }
		  return t;
	  }
  } // throws EmptyQueueException
  const Task& front() const{
    if(isEmpty()){
		  throw EmptyQueueException();
	  }
	  else{
		  return head->getTask();
	  }
  } // throws EmptyQueueException
  bool isEmpty() const{
    if(head == nullptr)return true;
    else{return false;}
  }
  int size() const{
    return cursize;
  }
  string toString() const{
  int n = size();
	if(n==0)return "[]";
	string s = "[";
	QueueNode* p = head;
	while(p!= nullptr){
		s = s + to_string(p->getTask().taskId);
		if(p->getNext()!=nullptr){
			s+=", ";
		}
		p = p->getNext();
	}
	return s+"]";
  }
};
