#include <iostream>
#include "EmptyQueueException.h"
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

class TaskQueue {
  private:
    int cursize;
    Node* head;
    Node* tail;
  public:
    TaskQueue():head(nullptr),tail(nullptr),cursize(0){}
    ~TaskQueue(){
      while(head!=nullptr){
        Node* a = head->getNext();
        delete head;
        head = a;
      }
      cursize = 0;
    }
  void enqueue(const Task& task){
    Node* n1 = new Node(task);
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
    Node* n1 = new Node(task);
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
		  Node* n2 = head->getNext();
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
