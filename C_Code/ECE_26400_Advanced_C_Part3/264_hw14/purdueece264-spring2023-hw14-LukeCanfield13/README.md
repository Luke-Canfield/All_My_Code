[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/_Uf4znj1)

# Convert Infix Expression to Postfix Expression

You should be able to reuse `list.c` and `list.h` from HW13. 
If your `list.c` was incorrect, this assignment gives you a chance to obtain scores if your `list.c` is correct for HW14.

Learning Goals
==============

* Understand stack
* Implement stack using linked list
* Convert Infix to Postfix

Infix and Postfix
=================

One advantage of postfix is that the precedence of operations is already
in postfix expression. Consider the following examples:

Infix       | Postfix
------------|----------
6 + 3 - 5   | 6 3 + 5 -
6 + 3 * 5   | 6 3 5 * +
(6 + 3) * 5 | 6 3 + 5 *

Each input line can be one of the following
1. A number
2. An operator `+`, `-`, or `*`
3. An open parenthesis `(`
4. A close parenthesis `)`

For simplicity, you may assume that the infix inputs are always valid.



Example 1
---------

A stack of operators is used to keep track of the order


Consider the input A * B + C (A, B, C are numbers).


Data Structure| Content
--------------|-------------
Operator Stack| `[]` (empty)
Output        | `[]` (empty)

First, A is a number and it is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[]` (empty)
Output        | `[A]` 

Next, the operator * is seen. It is pushed to the operator stack.


Data Structure| Content
--------------|-------------
Operator Stack| `[*]` 
Output        | `[A]` 

The operand B is seen. B is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[*]` 
Output        | `[A B]` 

Data Structure| Content
--------------|-------------
Operator Stack| `[*]` 
Output        | `[A B]` 

Next, read the operator +. **Since it has lower precedence, pop * and add it to the output.**  Push + to the stack.

Data Structure| Content
--------------|-------------
Operator Stack| `[+]` 
Output        | `[A B *]` 

The operand C is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[+]` 
Output        | `[A B * C]` 

Nothing is left in the input. Pop the stack and append it to the end of the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[]` 
Output        | `[A B * C +]` 

Example 2
---------

Consider the input A + B * C 


Data Structure| Content
--------------|-------------
Operator Stack| `[]` (empty)
Output        | `[]` (empty)


A is a number and it is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[]` (empty)
Output        | `[A]` 

Next, the operator + is seen. It is pushed to the operator stack.

Data Structure| Content
--------------|-------------
Operator Stack| `[+]` 
Output        | `[A]` 

The operand B is seen. B is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[+]` 
Output        | `[A B]` 

Next, read the operator *. **It has a higher precedence than + in the
stack and push it to the stack.**

Data Structure| Content
--------------|-------------
Operator Stack| `[+*]` 
Output        | `[A B]` 


The operand C is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[+*]` 
Output        | `[A B C]` 

Nothing is left in the input. Pop the stack and append it to the end of the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[+]` 
Output        | `[A B C *]` 

Keep popping and appending to the end of the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[]` 
Output        | `[A B C * +]` 

Example 3
---------

Consider the input A * (B + C)


Data Structure| Content
--------------|-------------
Operator Stack| `[]` (empty)
Output        | `[]` (empty)


A is a number and it is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[]` (empty)
Output        | `[A]` 

Next, the operator * is seen. It is pushed to the operator stack.

Data Structure| Content
--------------|-------------
Operator Stack| `[*]` 
Output        | `[A]`

An open parenthesis is seen. Push it to the stack.

Data Structure| Content
--------------|-------------
Operator Stack| `[* (]` 
Output        | `[A]`

The operand B is seen and it is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[* (]` 
Output        | `[A B]` 

Next, read the operator + and push it to the stack.

Data Structure| Content
--------------|-------------
Operator Stack| `[* ( +]` 
Output        | `[A B]` 

The operand C is added to the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[* ( +]` 
Output        | `[A B C]` 


Next, the close parenthesis is seen. **Pop the operator(s) in the stack until the open parenthesis is seen.**

Data Structure| Content
--------------|-------------
Operator Stack| `[*]` 
Output        | `[A B C + ]` 

Nothing is left in the input. Pop the stack and append it to the end of the output.

Data Structure| Content
--------------|-------------
Operator Stack| `[]` 
Output        | `[A B C + *]` 


Example 4
---------

Consider the input (A + B) * (C + D) * (E + F).  


Data Structure| Content                   | Action
--------------|---------------------------|-----------------------
Operator Stack| `[]` (empty)              |
Output        | `[]` (empty)              |
Operator Stack| `[(]`                     | read and push `(`
Output        | `[]`                      |
Operator Stack| `[(]`                     | 
Output        | `[A]`                     | read and output `A`
Operator Stack| `[(+]`                    | read and push `+`
Output        | `[A]`                     |
Operator Stack| `[(+]`                    | 
Output        | `[A B]`                   | read and output `B`
Operator Stack| `[]`                      | read `)`, pop until `(`
Output        | `[A B +]`                 | 
Operator Stack| `[*]`                     | read and push `*`
Output        | `[A B +]`                 |
Operator Stack| `[* (]`                   | read and push `(`
Output        | `[A B + ]`                |
Operator Stack| `[* (]`                   | 
Output        | `[A B + C]`               | read and output `C`
Operator Stack| `[* ( +]`                 | read and push `+`
Output        | `[A B + C]`               |
Operator Stack| `[* ( +]`                 | 
Output        | `[A B + C D]`             | read and output `D`
Operator Stack| `[* ]`                    | read `)`, pop until `(`
Output        | `[A B + C D +]`           |  
Operator Stack| `[]`                      | read `*`. It has the same precedence, pop `*` and add to output
Output        | `[A B + C D + *]`         |
Operator Stack| `[* ]`                    | push `*`
Output        | `[A B + C D + *]`         | 
Operator Stack| `[* (]`                   | read and push `(`
Output        | `[A B + C D + *]`         | 
Operator Stack| `[* (]`                   | read and output `E`
Output        | `[A B + C D + * E]`       |  
Operator Stack| `[* ( +]`                 | read and push `+`
Output        | `[A B + C D + * E]`       |
Operator Stack| `[* ( +]`                 | 
Output        | `[A B + C D + * E F]`     | read and output `F`
Operator Stack| `[* ]`                    | read `)`, pop until `(`
Output        | `[A B + C D + * E F + ]`  | 
Operator Stack| `[]`                      | pop the stack and output
Output        | `[A B + C D + * E F + *]` |






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
