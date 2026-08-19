#include "Task.h"
#include "TaskManager.h"

#include <iostream>
#include <string>

/*
 * TaskManagerTester.cpp
 * Unit-style checks for the TaskManager controller. Do not modify this file.
 *
 * If you run this without implementing the stubs, you should see:
 *   std::runtime_error: Not implemented yet
 */

static void expect(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << std::endl;
        std::exit(1);
    }
    std::cout << "PASSED: " << message << std::endl;
}

int main() {
    std::cout << "=== TaskManager Tester ===" << std::endl;

    TaskManager manager;

    // Test Priority Routing
    manager.receiveTask(Task(101, "Task-101", 2)); // Prio 2: Jumps to timeline
    manager.receiveTask(Task(102, "Task-102", 1)); // Prio 1: Front of inbox
    manager.receiveTask(Task(103, "Task-103", 0)); // Prio 0: Back of inbox

    // Timeline should already have 101 without processing
    expect(manager.printTimeline() == "[101]", "Priority 2 jumps straight to timeline");

    // Process should pull 102 first (Priority 1), then 103 (Priority 0)
    expect(manager.processNextTask() == 102, "processNextTask pulls Priority 1 task first");
    expect(manager.printTimeline() == "[101, 102]", "timeline after processing 102");

    // Test Delete and Undo
    expect(manager.deleteTask(101) == 101, "deleteTask removes 101");
    expect(manager.printTimeline() == "[102]", "timeline after delete");

    expect(manager.undo() == 101, "undo restores 101 to the back of timeline");
    expect(manager.printTimeline() == "[102, 101]", "timeline after undo");

    // Process the last item in inbox (103)
    expect(manager.processNextTask() == 103, "processNextTask pulls Priority 0 task last");
    expect(manager.printTimeline() == "[102, 101, 103]", "timeline after processing 103");

    // Test Dual-Mode Complete
    expect(manager.completeTask(102) == 102, "completeTask(id) removes specific task");
    expect(manager.printTimeline() == "[101, 103]", "timeline after specific complete");

    expect(manager.completeTask() == 101, "completeTask() removes front task");
    expect(manager.printTimeline() == "[103]", "timeline after front complete");

    // Test edge cases
    expect(manager.processNextTask() == -1, "processNextTask on empty inbox returns -1");
    expect(manager.deleteTask(999) == -1, "deleteTask missing id returns -1");
    expect(manager.completeTask(999) == -1, "completeTask missing id returns -1");
    expect(manager.undo() == -1, "undo on empty history returns -1");

    TaskManager fresh;
    expect(fresh.undo() == -1, "undo on a fresh manager returns -1");

    std::cout << "=== All TaskManager tests passed ===" << std::endl;
    return 0;
}
