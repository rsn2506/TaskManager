#include "Task.h"
#include "TaskManager.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
/*
 * DeadlinePanic.cpp
 *
 * Reads an input file of Task Manager operations and prints results for
 * every non-RECEIVE action, as specified in the assignment handout.
 *
 * Usage: ./DeadlinePanic <inputfile>
 *
 * Implement the operation loop below. You MUST drive the simulation only
 * through TaskManager (which in turn uses your Part A ADTs).
 */

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <inputfile>" << endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        cerr << "Failed to open input file: " << argv[1] << endl;
        return 1;
    }

    // TODO: Implement the Deadline Panic driver.
    //
    // Pseudocode:
    TaskManager manager;
    int N;
    input >> N;
    string s;
    for(int opNum = 1; opNum <= N; opNum++){
         int actionId;
         input >> actionId;
         switch(actionId){
           case 1:{ //RECEIVE  taskId priority
           int t,p;
           input >> t >> p;
           manager.receiveTask(Task(t, to_string(t), p));
           break;
            }
           case 2:{// PROCESS
           cout<<opNum << " " << manager.processNextTask() << endl;
           break;
            }
           case 3:{// DELETE   taskId
           int t;
           input >> t;
           cout<<opNum << " " << manager.deleteTask(t) << endl;
    //           -> print: opNum << " " << manager.deleteTask(taskId)
           break;
            }
           case 4: { // COMPLETE [taskId]
           int ch;
            
           while ((ch = input.peek()) == ' ' || ch == '\t') {
               input.get(); 
            }
            
            
           if (ch >= '0' && ch <= '9') {
               int t;
               input >> t;
               cout << opNum << " " << manager.completeTask(t) << endl;
            } 
           else {
                
               cout << opNum << " " << manager.completeTask() << endl;
            }
           break;
           }
           case 5:{// UNDO
           cout << opNum << " " << manager.undo() << endl;
           break;
           }
           case 6:{// PRINT
           cout << opNum << " " << manager.printTimeline() << endl;
    //           -> print: opNum << " " << manager.printTimeline()
           break;
           }
    //
    // Do not print anything for RECEIVE.
    // Do not print extraneous debugging output.
    }
    }
    return 0;
}
