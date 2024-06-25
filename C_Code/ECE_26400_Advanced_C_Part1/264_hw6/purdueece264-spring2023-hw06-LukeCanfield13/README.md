# Read Line from File and Count Word

### Due 02/20 at 11:59pm

Learning Goals 
==============

This assignment asks you to write a program that reads lines from a file,
counts how many times a word occurs, and report the result.

You will learn to
* Read lines and store as strings
* Detect whether one string is inside another string

Read Line from File and Count Words
===================================

This assignment uses `fgets` to read strings from a file, uses
`strstr` to find whehther a word is inside the string from the file.
This assignment is a simplified version of the `grep` command in
Linux.

What To Do
==========

You need to write a function called `countWord(char * filename, char * word, char * line, int size)` 
that opens a file named `filename`, counts the number of occurences of given word in the file,
and returns it. If `fopen()` fails, return -1, and **DO NOT** fclose.
Further instructions are in the comments in the function in file `filestr.c`.

As you develop your code, do not forget to use version control. As you solve parts of the problem, use `git add` and `git commit` to preserve the latest version of the code. Periodically use `git push` to sync your code with your GitHub repository.

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


Test Inputs
===========

The test inputs are [famous speeches](https://www.artofmanliness.com/articles/ooda-loop/).
