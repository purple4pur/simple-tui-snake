imp = ../library_cpp/include/console.cc ../library_cpp/include/point.cc *.cc

all: compile

compile:
	@g++ main.cpp ${imp} -o Snake -O3 -static-libgcc

run:
	@./Snake
