# Read Characters from File

### Due 02/06 at 11:59pm

Learning Goals 
==============

This assignment asks you to write a program that reads characters from a file.

You will learn to
* Read characters from file
* Understand file permission
* Convert between number of character by the ASCII table
* Handle errors (when fopen fails)

Read Data from File
===================

Files provide permanent storage of information. Before reading from or
writing to a file, a file has to be opened (by calling `fopen`). When
a file is no longer used, it need to be closed (by calling `fclose`).

Calling `fopen` may fail for several reasons. If `fopen` wants to read
a file, the file may not exist. It is also possible that the file
exists but cannot be read. If `fopen` wants to write a file, the file
may exist but it is read-only. It is also possible that there is no
space available on the disk.

What you need to do
===================

You need to write a function called `countChar(char * filename, int *
counts, int size)` that opens a file named `filename`. If it fails
return false, **DO NOT** `fclose`.

You have to store the count of each
charecter in the count array. Further instructions are in the comments
in the function in file `filechar.c`

You also need to write a function called `printCounts(int * counts,
int size)` that prints out the count of each charecter.  Further
instructions are in the comments in the function in file `filechar.c`

Test Your Program
=================

You must test whether your program can handle unexpected situations, such as

* No name of the input file (argc < 2)
* The input file cannot be open
* You must not assume that `size` is 256

Your program must not crash for these situations.


SUBMISSION
==============

As you develop your code, do not forget to use version control. As you solve parts of the problem, use `git add` and `git commit` to preserve the latest version of the code. Periodically use `git push` to sync your code with your GitHub repository.

When you are ready to submit your code for grading, you need to *tag* the version you want us to grade. A tag is a way of assigning a name to a particular version of code. We look for the tag `final_ver` to decide what to grade.

1. Tag your local code: `> git tag final_ver`
2. Push the tag to GitHub: `> git push origin final_ver`

If you later decide you want to update the version you submit, you can tag a different version:

1. Update the tag: `> git tag final_ver -f`
2. Push the tag to GitHub: `git push origin final_ver -f`

We will grade whichever version has the `final_ver` tag at the due date.



