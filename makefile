# C++ Makefile
MAIN=main.cpp
PROJECT_NAME=pokebattle
SRCS=gamecore/*
INCLUDE=-Iinclude

compile: $(MAIN)
	g++ -o $(PROJECT_NAME) $(MAIN) $(SRCS) $(INCLUDE)

run: $(PROJECT_NAME)
	./$(PROJECT_NAME)

debug-compile: $(MAIN)
	g++ -g -o $(PROJECT_NAME) $(MAIN) $(SRCS)

debug: $(PROJECT_NAME)
	gdb $(PROJECT_NAME) core
