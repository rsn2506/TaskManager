#pragma once //to prevent multiple including of Task.h header file
#include <iostream>
#include "EmptyStackException.h"
#include "Task.h"
using namespace std;

class StackNode{// Node class changed to StackNode to avoid confusion with QueueNode class in TaskQueue.h

private:
Task task;
StackNode* next;

public:
StackNode():task(),next(nullptr){}
StackNode(Task t, StackNode* t_p = nullptr):task(t),next(t_p){}

const Task& getTask() const{
return task;
}

StackNode* getNext() const{
return next;
}

void setTask(const Task& newTask) {
task = newTask;
}

//next is declared as a StackNode pointer. 
//But in setNext if it is set to const StackNode pointer, c++ wont allow const beside param
void setNext(StackNode* t_n) {
next = t_n;
}

};

class TaskStack {

private:
StackNode* head;
int cursize;

public:

TaskStack():head(nullptr),cursize(0){}


~TaskStack() {
	while(head!= nullptr){
		StackNode* a = head->getNext();
		delete head;
		head = a;
	}
	cursize = 0;
	return;
}

void push(const Task& task){
	StackNode* n1 = new StackNode(task);
	n1->setNext(head);
	head = n1;
	cursize = cursize+1;
}

Task pop(){
	if(isEmpty()){
		throw EmptyStackException();
	}
	else{
		StackNode* n2 = head->getNext();
		Task t = head->getTask();
		delete head;
		cursize = cursize - 1;
		head = n2;
		return t;
	}
} // throws EmptyStackException

const Task& top() const{
	if(isEmpty()){
		throw EmptyStackException();
	}
	else{
		return head->getTask();
	}
} // throws EmptyStackException

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
	StackNode* p = head;
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

