# Part_B Makefile
# Links against Part_A objects in ../build and produces DeadlinePanic /
# TaskManagerTester executables there as well.

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -I../part_A
BUILD    = ../build

PART_A_OBJS = $(BUILD)/Task.o \
              $(BUILD)/TaskQueue.o \
              $(BUILD)/TaskStack.o \
              $(BUILD)/TaskTimeline.o

.PHONY: all part_a run_tester run_panic clean dirs

all: dirs part_a $(BUILD)/TaskManagerTester $(BUILD)/DeadlinePanic

dirs:
	mkdir -p $(BUILD)

part_a:
	$(MAKE) -C ../part_A all

$(BUILD)/TaskManager.o: TaskManager.cpp TaskManager.h
	$(CXX) $(CXXFLAGS) -c TaskManager.cpp -o $@

$(BUILD)/TaskManagerTester: TaskManagerTester.cpp $(BUILD)/TaskManager.o $(PART_A_OBJS)
	$(CXX) $(CXXFLAGS) TaskManagerTester.cpp $(BUILD)/TaskManager.o $(PART_A_OBJS) -o $@

$(BUILD)/DeadlinePanic: DeadlinePanic.cpp $(BUILD)/TaskManager.o $(PART_A_OBJS)
	$(CXX) $(CXXFLAGS) DeadlinePanic.cpp $(BUILD)/TaskManager.o $(PART_A_OBJS) -o $@

run_tester: all
	$(BUILD)/TaskManagerTester

run_panic: all
	$(BUILD)/DeadlinePanic sampleInputFile.txt

clean:
	rm -f $(BUILD)/TaskManager.o \
	      $(BUILD)/TaskManagerTester \
	      $(BUILD)/DeadlinePanic
