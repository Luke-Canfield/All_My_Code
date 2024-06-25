# Quick Sort

## Due 02/27 at 11:59pm

Learning Goals 
==============

This assignment asks you to write a program that uses *qsort* (a
function provided by C) to sort an array of integers in the ascending
order.

You will learn to
* Count the number of integers in a file
* Allocate memory (an array) to store the integers
* Read integers from the file and store them in the array
* Call `qsort` function to sort the integers
* Write the sorted array to another file
* Release memory
* Check memory error using `valgrind`

Quick Sort
==============

The [`qsort` function](https://linux.die.net/man/3/qsort) is a generic
function in C for sorting arrays. Please go to the link and read the
explanation.  For this assignment, you need to understand how to use
`qsort`. You do not need to understand the algorithm. You will learn
the algorithm later (after understanding recursion).

What You Need to Do
===================

Warning: This assignment is *much much* harder than all previous assignments combined. You must start early.

 Need to complete the following functions:
 * `int main(int argc, char * * argv)`
 * `int countInt(char* filename)`
 * `bool readInt(char* filename, int * intArr, int size)`
 * `bool writeInt(char* filename, int * intArr, int size)`
 * `int compareInt(const void *p1, const void *p2)`

Check Memory Leak
=================

Your program must not crash and must not leak memory.  **From now on,
you will lose one point for every leaked byte.** The leaked bytes will
accumulate across all test cases in each assignment. If your program
leaks memory, it is very likely that you will receive zero.  Please
use `valgrind` to check memory errors. A program that leaks memory is
like an airplane that leaks fuel. Neither can be accepted.

WHAT TO SUBMIT
==============


You **must** follow the instructions precisely. Failing to follow
these instructions will likely make you receive zero in this
assignment.  Your score **is determined by your submission**, nothing
else.  The teaching staff is strictly prohibited seeing anything on
your computer for grading.

When you are ready to submit your code for grading, you need to *tag* the version you want us to grade. A tag is a way of assigning a name to a particular version of code. We look for the tag `final_ver` to decide what to grade.

1. Tag your local code: `> git tag final_ver`
2. Push the tag to GitHub: `> git push origin final_ver`

If you later decide you want to update the version you submit, you can tag a different version:

1. Update the tag: `> git tag final_ver -f`
2. Push the tag to GitHub: `git push origin final_ver -f`

We will grade whichever version has the `final_ver` tag at the due date.
