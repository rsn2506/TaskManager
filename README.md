# TaskManager
A taskmanager to track and solve tasks within deadlines

## Overview
This project is a high-performance, command-line Task Management System written in C++. It simulates a priority-based dispatcher that routes, schedules, and processes tasks. 

Instead of relying on standard library containers (like `std::vector` or `std::queue`), the core of this project relies entirely on **custom-built, dynamically allocated data structures** to ensure strict O(1) time complexity for all primary routing operations.

## Architecture & Data Structures
The project is divided into two main layers: the foundational data structures (Part A) and the system controller/driver (Part B).

### 1. Custom Abstract Data Types (ADTs)
a.   **TaskQueue (Singly-Linked Queue):** Handles standard and urgent tasks. Guarantees O(1) insertion at both the front and rear.
b.   **TaskStack (Singly-Linked Stack):** Acts as the history buffer for the `UNDO` feature. Guarantees O(1) push and pop operations.
c.   **TaskTimeline (Doubly-Linked List):** The official schedule of processed and emergency tasks. Supports $O(1)$ insertions at both ends and allows for arbitrary node removal by `taskId` with full pointer rewiring.

### 2. TaskManager (The Controller)
Acts as the central dispatcher. It holds instances of the ADTs and routes incoming tasks based on their priority level:
a.   **Priority 0 (Standard):** Enqueued to the back of the inbox.
b.   **Priority 1 (Urgent):** Inserted at the front of the inbox.
c.   **Priority 2 (Emergency):** Bypasses the inbox entirely and is pushed directly to the front of the official timeline.

## Technical Highlights
a.   **Manual Memory Management:** Strict adherence to the **C++ Rule of Three** (custom Destructors, Copy Constructors, and Copy Assignment Operators) to prevent memory leaks, shallow copy bugs, and double-free segmentation faults.
b.   **Robust File I/O:** Safely parses varying commands and optional parameters from a text file, utilizing stream peeking and precise character consumption.
c.   **Multi-File Compilation:** Fully modularized `.h` and `.cpp` architecture driven by a custom `Makefile`.

## Build and Execution Instructions
This project utilizes a `Makefile` for easy compilation. Ensure you have `g++` and `make` installed on your system.

### Compiling the Project
Navigate to the root directory and run:
make all

This will generate the necessary object files and place the executable binaries inside a build directory.

Running the Tests
To verify the integrity of the data structures and routing logic:

Bash - make run_tester
Running the Simulation
To run the main driver program against an input file:

Bash - make run_panic
(Note: The Makefile is configured to automatically feed sampleInputFile.txt into the simulation).

Supported Commands
The driver program parses a text file containing the following operation codes:

1 <taskId> <priority>: RECEIVE a task and route it based on priority.

2: PROCESS the next task in the inbox and move it to the timeline.

3 <taskId>: DELETE a task from the timeline and push it to the undo stack.

4 [taskId]: COMPLETE a task (permanently remove it). If no ID is provided, completes the front task on the timeline.

5: UNDO the last deleted task, appending it back to the end of the timeline.

6: PRINT the current state of the timeline.
