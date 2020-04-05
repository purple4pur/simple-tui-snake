imp = ../library_cpp/include/console.cc ../library_cpp/include/point.cc *.cc

all: compile

compile:
	@g++ -Wall main.cpp ${imp} -o Snake -O3 -static

run:
	@./Snake
