# Read Numbers from File

### Due 02/13 at 11:59pm

Learning Goals 
==============

This assignment asks you to write a program that reads numbers from a file,
adds the numbers, and saves the sum into a file.

You will learn to
* Read integers from file, add them, write the result to file
* Use pointer to pass information to caller

Read Data from File and Write Data to File
==========================================

The previous assignment uses `fgetc` to read one character at a time.
This assignment asks you to use `fscanf` to read numbers. To write a
number, you can use `fprintf`.

What You Need To Do
===================

You need to write a function called `addFile(char * filename, int *
sum)` that opens a file named filename. If it fails, return false, and
**DO NOT** `fclose()`. You have to read the integers in the file, and
store the sum. Further instructions are in the comments in the
function in file `fileint.c`.

You also need to write a function called `writeSum(char * filename,
int sum)` that writes the sum as an integer which name is
`filename`. Further instructions are in the comments in the function
in file `fileint.c`


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


