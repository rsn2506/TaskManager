#include "TaskQueue.h"
#include "EmptyQueueException.h"
#include <stdexcept>
#include <string>

TaskQueue::TaskQueue() : head_(nullptr), tail_(nullptr), size_(0) {}

TaskQueue::~TaskQueue() {
    // TODO: Free all dynamically allocated nodes.
    // Starter stub intentionally does not throw from the destructor.
}

void TaskQueue::enqueue(const Task& task) {
    // TODO: Insert at the rear in O(1) time.
    (void)task;
    throw std::runtime_error("Not implemented yet");
}

void TaskQueue::insertFirst(const Task& task) {
    // TODO: Insert at the front in O(1) time.
    (void)task;
    throw std::runtime_error("Not implemented yet");
}

Task TaskQueue::dequeue() {
    // TODO: Remove from the front in O(1) time.
    // Throw EmptyQueueException if the queue is empty.
    throw std::runtime_error("Not implemented yet");
}

const Task& TaskQueue::front() const {
    // TODO: Return a const reference to the front task without removing it.
    // Throw EmptyQueueException if the queue is empty.
    throw std::runtime_error("Not implemented yet");
}

bool TaskQueue::isEmpty() const {
    // TODO: Return true iff the queue contains no tasks.
    throw std::runtime_error("Not implemented yet");
}

int TaskQueue::size() const {
    // TODO: Return the number of tasks currently in the queue.
    throw std::runtime_error("Not implemented yet");
}

std::string TaskQueue::toString() const {
    // TODO: Return "[id1, id2, ...]" from front to rear (ids only), or "[]" if empty.
    throw std::runtime_error("Not implemented yet");
}
