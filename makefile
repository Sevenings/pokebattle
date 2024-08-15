# C++ Makefile
MAIN=main.cpp
PROJECT_NAME=pokebattle

INCLUDE_FOLDER=include

compile: $(MAIN)
	g++ -o $(PROJECT_NAME) $(MAIN) -I$(INCLUDE_FOLDER)

run: $(PROJECT_NAME)
	./$(PROJECT_NAME)


