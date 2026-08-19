#include "Task.h"
#include <stdexcept>

Task::Task() : taskId(0), description(""), priority(0) {}

Task::Task(int taskId, const std::string& description, int priority)
    : taskId(taskId), description(description), priority(priority) {
    // TODO: Optionally validate that priority is in {0, 1, 2}.
    throw std::runtime_error("Not implemented yet");
}

std::string Task::toString() const {
    // TODO: Return exactly: Task(id=<id>, desc="<description>", priority=<priority>)
    // Example: Task(id=1, desc="Task-1", priority=2)
    throw std::runtime_error("Not implemented yet");
}
