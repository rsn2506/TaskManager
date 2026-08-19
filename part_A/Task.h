#pragma once
#include <iostream>
#include <string>

using namespace std;

class Task {

public:

int taskId;

string description;

int priority; // 0 - standard, 1 - urgent, 2 - emergency

Task():taskId(),description(),priority(){}

Task(int taskId, const string& description, int priority):taskId(taskId),description(description),priority(priority){}

string toString() const{

return "Task(id=" + to_string(taskId) + ", desc=\"" + description + "\", priority=" + to_string(priority) + ")";

}

}; 

