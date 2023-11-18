CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: signal_handling

signal_handling: signal_handling.cpp
	$(CXX) $(CXXFLAGS) -o signal_handling signal_handling.cpp
