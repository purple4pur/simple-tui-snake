imp = ../library_cpp/include/console.cc ../library_cpp/include/point.cc *.cc

all: debug

debug:
	@g++ -Wall main.cpp ${imp} -o Snake-debug

release:
	@g++ main.cpp ${imp} -o Snake-release -O3 -static
