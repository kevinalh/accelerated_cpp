CXX = clang++
CC = clang++

CFLAGS = -g -Wall

all: evaluate

evaluate: main.o median.o Student_info.o grades.o
	$(CXX) $(CFLAGS) -o evaluate main.o median.o Student_info.o grades.o

main.o: main.cpp grades.h Student_info.h
	$(CXX) $(CFLAGS) -c main.cpp

median.o: median.cpp median.h
	$(CXX) $(CFLAGS) -c median.cpp

Student_info.o: Student_info.cpp Student_info.h
	$(CXX) $(CFLAGS) -c Student_info.cpp

grades.o: grades.cpp grades.h median.h Student_info.h
	$(CXX) $(CFLAGS) -c grades.cpp

