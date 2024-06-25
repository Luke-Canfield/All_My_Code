
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFLAGS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE  

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw11: $(OBJS) 
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw11

.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

testall: test1 test2 test3

test1: hw11
	./hw11 4 | sort > output1
	diff -w output1 expected/expected4

test2: hw11
	./hw11 8 | sort > output2
	diff -w output2 expected/expected8

test3: hw11
	./hw11 11 | sort > output3
diff -w output3 expected/expected11

clean:
	rm -f hw11 *.o output?

