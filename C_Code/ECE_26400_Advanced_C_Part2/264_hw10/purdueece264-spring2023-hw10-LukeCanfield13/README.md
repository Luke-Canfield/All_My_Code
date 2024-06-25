
# Who Gets the Cake (Part 2)

## Due 03/20 at 11:59pm

Learning Goals 
==============

* Insert and delete nodes in a linked list 

Changes from HW03Cake
=====================

In HW03, an array is used to keep track who is still in the
game. In this assignment, a linked list is used.  The output of your
program should match the output of HW03. In addition, the linked
list is printed every time one number is removed.

The files in `expected` directory have `-DDEBUG` in `Makefile` to turn
on the code printing the lists starting from the nodes to be
eliminated.  If `Makefile` does not have `-DDEBUG`, the outputs should
be the same as the files in HW03.

Initialize Pointers
===================

You should *always* initialize pointers to NULL. Many students lose
points unnecessarily because they do not initialize pointers to
NULL. Uninitialized pointers can make your programs' behavior
unpredictable.  Your programs may "work" when you test and fail when
they are graded.

Some students say, "I don't want to initialize pointers unnecessarily
because I know I will assign meaningful values later." Unfortunately,
unexpected execution paths (due to `if` conditions) may have some
pointers unitialized.  Some students say, "Unnecessary initialization
slow down my program. I want my program to be really fast."  Yes, it
is true that assigning `NULL` to a pointer may slow down your
programs, by about half a nanosecond. If you run the programs on
multi-issue machines (for most desktops and laptops today), the
assignment may not take any additional time. The unpredictable
behavior of your program may take several hours to debug. It is unwise
to save half a nanosecond of machine time and spend several hours of
your personal time.

Printing ListNode
===================

You should call `printListNode` each time BEFORE you delete any node 
and print the node value. In the expected files, `printListNode` is not
called for the last value in the list. Follow the 
expected files format. You can turn on the DEBUG flag in your Makefile
for printing.

Submission
==========

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
