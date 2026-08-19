#include <iostream>
#include "EmptyStackException.h"
using namespace std;

class Node{

private:
Task task;
Node* next;

public:
Node():task(),next(nullptr){}
Node(Task t, Node* t_p = nullptr):task(t),next(t_p){}

const Task& getTask() const{
return task;
}

Node* getNext() const{
return next;
}

void setTask(const Task& newTask) {
task = newTask;
}

//next is declared as a Node pointer. 
//But in setNext if it is set to const Node pointer, c++ wont allow const beside param
void setNext(Node* t_n) {
next = t_n;
}

};

class TaskStack {

private:
Node* head;
int cursize;

public:

TaskStack():head(nullptr),cursize(0){}


~TaskStack() {
	while(head!= nullptr){
		Node* a = head->getNext();
		delete head;
		head = a;
	}
	cursize = 0;
	return;
}

void push(const Task& task){
	Node* n1 = new Node(task);
	n1->setNext(head);
	head = n1;
	cursize = cursize+1;
}

Task pop(){
	if(isEmpty()){
		throw EmptyStackException();
	}
	else{
		Node* n2 = head->getNext();
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
	Node* p = head;
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

