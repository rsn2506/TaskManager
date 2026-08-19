#include "Task.h"
#include "TaskQueue.h"
#include "TaskStack.h"
#include "TaskTimeline.h"
#include "EmptyQueueException.h"
#include "EmptyStackException.h"

#include <iostream>
#include <string>

/*
 * PartATester.cpp
 * Exercises the foundational ADTs. Do not modify this file.
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
    std::cout << "=== Part A Tester ===" << std::endl;

    // --- Task ---
    Task t1(1, "Task-1", 2);
    Task t2(2, "Task-2", 1);
    Task t3(3, "Task-3", 0);
    Task t4(4, "Task-4", 1);
    expect(t1.taskId == 1 && t1.priority == 2, "Task fields are set correctly");
    expect(t1.toString() == "Task(id=1, desc=\"Task-1\", priority=2)",
           "Task toString exact format");

    // --- TaskQueue ---
    TaskQueue q;
    expect(q.isEmpty(), "Fresh TaskQueue is empty");
    q.enqueue(t1);
    q.enqueue(t2);
    q.enqueue(t3);
    q.insertFirst(t4);
    expect(q.size() == 4, "TaskQueue size after 3 enqueues and 1 insertFirst");
    expect(q.toString() == "[4, 1, 2, 3]", "TaskQueue toString with insertFirst");
    expect(q.front().taskId == 4, "TaskQueue front peeks without removing");
    Task dequeued = q.dequeue();
    expect(dequeued.taskId == 4, "TaskQueue dequeue returns front");
    expect(q.toString() == "[1, 2, 3]", "TaskQueue toString after one dequeue");

    // --- TaskStack ---
    TaskStack s;
    expect(s.isEmpty(), "Fresh TaskStack is empty");
    s.push(t1);
    s.push(t2);
    s.push(t3);
    expect(s.size() == 3, "TaskStack size after 3 pushes");
    expect(s.toString() == "[3, 2, 1]", "TaskStack toString top-to-bottom");
    expect(s.top().taskId == 3, "TaskStack top peeks without removing");
    Task popped = s.pop();
    expect(popped.taskId == 3, "TaskStack pop returns top");
    expect(s.toString() == "[2, 1]", "TaskStack toString after one pop");

    // --- TaskTimeline ---
    TaskTimeline timeline;
    expect(timeline.isEmpty(), "Fresh TaskTimeline is empty");
    timeline.insertLast(t1);
    timeline.insertLast(t2);
    timeline.insertFirst(t3); // timeline should now be [3, 1, 2]
    expect(timeline.size() == 3, "TaskTimeline size after inserts");
    expect(timeline.toString() == "[3, 1, 2]", "TaskTimeline toString head-to-tail");
    Task removedFirst = timeline.removeFirst();
    expect(removedFirst.taskId == 3, "TaskTimeline removeFirst returns head");
    expect(timeline.toString() == "[1, 2]", "TaskTimeline toString after removeFirst");
    expect(timeline.remove(1) == true, "TaskTimeline remove existing id");
    expect(timeline.toString() == "[2]", "TaskTimeline toString after remove");
    expect(timeline.remove(99) == false, "TaskTimeline remove missing id");

    std::cout << "=== All Part A tests passed ===" << std::endl;
    return 0;
}
