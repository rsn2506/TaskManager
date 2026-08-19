#include <iostream>
#include "Task.h"
#include "EmptyQueueException.h"
using namespace std;

class DoubleNode{
  private:
    Task task;
    DoubleNode* prev;
    DoubleNode* next;
  public:
    DoubleNode():task(),prev(nullptr),next(nullptr){}
    DoubleNode(Task t, DoubleNode* n1 = nullptr, DoubleNode* n2 = nullptr):task(t),prev(n1),next(n2){}
    
    const Task& getTask() const{
      return task;
    }
    DoubleNode* getprev() const{
      return prev;
    }
    DoubleNode* getnext() const{
      return next;
    }
    void setTask(const Task& t){
      task = t;
    }
    void setPrev(DoubleNode* n1){
      prev = n1;
    }
    void setNext(DoubleNode* n2){
      next = n2;
    }
    // cant add const before{ or before Task* as the assignment find function is clearly Task* which is non-constant type
    Task* getTaskPointer(){
    return &task;
    }
};

class TaskTimeline {
  private:
    int cursize;
    DoubleNode* head;
    DoubleNode* tail;
  public:
    TaskTimeline():cursize(0),head(nullptr),tail(nullptr){}
    ~TaskTimeline(){
      while(head != nullptr){
        DoubleNode* a = head->getNext();
        delete head;
        head = a;
      }
      tail = nullptr;
      cursize = 0;
    }
    void insertFirst(const Task& t){
      DoubleNode* n1 = new DoubleNode(t);
      if(isEmpty()){
        head = n1;
        tail = n1;
        cursize = cursize + 1;
        return;
      }
      n1->setNext(head);
      head->setPrev(n1);
      head = n1;
      cursize = cursize + 1;
    } // prepend, O(1)
    void insertLast(const Task& t){
      DoubleNode* n1 = new DoubleNode(t);
      if(isEmpty()){
        head = n1;
        tail = n1;
        cursize = cursize + 1;
        return;
      }
      tail->setNext(n1);
      n1->setPrev(tail);
      tail = n1;
      cursize = cursize + 1;
    } // append, O(1)
    Task removeFirst(){
      if(isEmpty()){
        throw EmptyQueueException();  
      }
      DoubleNode* r = head;
      r = r->getNext();
      Task t = head->getTask();
      delete head;
      head = r;
      if (head == nullptr){
        tail = nullptr;
        cursize = cursize - 1;
        return t;
      }
      head->setPrev(nullptr);
      cursize = cursize - 1;
      return t;
    } // removes and returns front task,throws if empty
    
    bool remove(int taskId){
      if(isEmpty())return false;
      else if(head->getTask().taskId == taskId){
        removeFirst();
        return true;
      }
      else if(tail->getTask().taskId == taskId){
        DoubleNode* n2 = tail->getPrev();
        tail->getPrev()->setNext(nullptr);
        delete tail;
        tail = n2;
        cursize = cursize - 1;
        return true;
      }
      
      DoubleNode* n2 = head;
      while(n2!= nullptr){
        if(n2->getTask().taskId == taskId){
          DoubleNode* x = n2->getPrev();
          DoubleNode* y = n2->getNext();
          x->setNext(n2->getNext());
          y->setPrev(x);
          delete n2;
          cursize = cursize - 1;
          n2 = y;
          return true;
        }
        n2 = n2->getNext();
      }
      return false;
      
    } // true if removed
    Task* find(int taskId){
      DoubleNode* n2 = head;
      while(n2!= nullptr){
        if(n2->getTask().taskId == taskId){
          return n2->getTaskPointer();
        }
        n2 = n2->getNext();
      }
      return nullptr;
    } // nullptr if absent
    void print() const{
      cout<<toString()<<endl;
    } // writes toString() followed by a newline
    string toString() const{
      int n = size();
	    if(n==0)return "[]";
	    string s = "[";
	    DoubleNode* p = head;
	    while(p!= nullptr){
		    s = s + to_string(p->getTask().taskId);
		    if(p->getNext()!=nullptr){
			    s+=", ";
		    }
		    p = p->getNext();
	    }
	    return s+"]";
    }
    bool isEmpty() const{
      if(cursize == 0)return true;
      else{return false;}
    }
    int size() const{
      return cursize;
    }
};
