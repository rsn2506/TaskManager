#include "TaskTimeline.h"
#include <iostream>
#include <stdexcept>
#include <string>

TaskTimeline::TaskTimeline() : head_(nullptr), tail_(nullptr), size_(0) {}

TaskTimeline::~TaskTimeline() {
    // TODO: Free all dynamically allocated nodes.
    // Starter stub intentionally does not throw from the destructor.
}

void TaskTimeline::insertFirst(const Task& task) {
    // TODO: Prepend in O(1) time.
    (void)task;
    throw std::runtime_error("Not implemented yet");
}

void TaskTimeline::insertLast(const Task& task) {
    // TODO: Append in O(1) time.
    (void)task;
    throw std::runtime_error("Not implemented yet");
}

Task TaskTimeline::removeFirst() {
    // TODO: Remove and return the first task in O(1) time.
    // Throw std::runtime_error (or a custom exception) if timeline is empty.
    throw std::runtime_error("Not implemented yet");
}

bool TaskTimeline::remove(int taskId) {
    // TODO: Remove the first node whose taskId matches. Return true on success.
    (void)taskId;
    throw std::runtime_error("Not implemented yet");
}

Task* TaskTimeline::find(int taskId) {
    // TODO: Return a pointer to the matching Task, or nullptr if absent.
    (void)taskId;
    throw std::runtime_error("Not implemented yet");
}

void TaskTimeline::print() const {
    // TODO: Print toString() followed by a newline.
    throw std::runtime_error("Not implemented yet");
}

std::string TaskTimeline::toString() const {
    // TODO: Return "[id1, id2, ...]" from head to tail (ids only), or "[]" if empty.
    throw std::runtime_error("Not implemented yet");
}

bool TaskTimeline::isEmpty() const {
    // TODO: Return true iff the timeline contains no tasks.
    throw std::runtime_error("Not implemented yet");
}

int TaskTimeline::size() const {
    // TODO: Return the number of tasks currently on the timeline.
    throw std::runtime_error("Not implemented yet");
}
