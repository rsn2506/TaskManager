# Part_A Makefile
# Builds foundational ADT objects into ../build and runs PartATester.

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
BUILD    = ../build

OBJS = $(BUILD)/Task.o \
       $(BUILD)/TaskQueue.o \
       $(BUILD)/TaskStack.o \
       $(BUILD)/TaskTimeline.o

.PHONY: all run clean dirs

all: dirs $(BUILD)/PartATester

dirs:
	mkdir -p $(BUILD)

$(BUILD)/Task.o: Task.cpp Task.h
	$(CXX) $(CXXFLAGS) -c Task.cpp -o $@

$(BUILD)/TaskQueue.o: TaskQueue.cpp TaskQueue.h Task.h EmptyQueueException.h
	$(CXX) $(CXXFLAGS) -c TaskQueue.cpp -o $@

$(BUILD)/TaskStack.o: TaskStack.cpp TaskStack.h Task.h EmptyStackException.h
	$(CXX) $(CXXFLAGS) -c TaskStack.cpp -o $@

$(BUILD)/TaskTimeline.o: TaskTimeline.cpp TaskTimeline.h Task.h
	$(CXX) $(CXXFLAGS) -c TaskTimeline.cpp -o $@

$(BUILD)/PartATester: PartATester.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) PartATester.cpp $(OBJS) -o $@

run: all
	$(BUILD)/PartATester

clean:
	rm -f $(BUILD)/Task.o \
	      $(BUILD)/TaskQueue.o \
	      $(BUILD)/TaskStack.o \
	      $(BUILD)/TaskTimeline.o \
	      $(BUILD)/PartATester
