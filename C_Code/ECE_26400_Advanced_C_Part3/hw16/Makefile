#Homework
BASE_NAME = frequencies 
ASG_NICKNAME = HW16

#Executables
EXECUTABLE = frequencies
EXECUTABLE_GCOV = $(EXECUTABLE)_gcov

#Filenames
SRC_C = frequencies.c
SRC_H = frequencies.h clog.h miniunit.h
TEST_C = test_frequencies.c
SUBMIT_FILES = $(SRC_C) $(TEST_C) $(SRC_H) Makefile

#System Variables
CC = gcc
CFLAGS = -g -std=c11 -Wall -Wshadow -Wvla -Werror -pedantic
CFLAGS_GCOV = $(CFLAGS) -fprofile-arcs -ftest-coverage
SHELL = /bin/bash

#Rules----------------------------------------------------------

$(EXECUTABLE): $(SRC_C) $(TEST_C) $(SRC_H)
	$(CC) -o $(EXECUTABLE) $(SRC_C) $(TEST_C) $(CFLAGS)

pretest: submit
	264test $(ASG_NICKNAME)

test:  $(EXECUTABLE)
	./$(EXECUTABLE)
	valgrind ./$(EXECUTABLE)

submit: $(SUBMIT_FILES)
	264submit $(ASG_NICKNAME) $(SUBMIT_FILES) 

coverage: $(SRC_C) $(TEST_C)
	$(CC) -o $(EXECUTABLE_GCOV) $(SRC_C) $(TEST_C) $(CFLAGS_GCOV)
	./$(EXECUTABLE_GCOV)
	gcov -f $(SRC_C)

clean: 
	rm -f $(EXECUTABLE) *.c.gcov *.gcda *.gcno 

.PHONY: submit test pretest coverage clean
