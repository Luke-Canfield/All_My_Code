function [w, t, v] = sampleFN(b, h, d)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
%   Function template for A09 - Problem 1, Part A
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
%Inputs
% b is the first input
% h is the second input
% d is the third input
%Outputs
% w is the first output
% t is the second output
% v is the third output

%% ____________________
%% CALCULATIONS

w = (d / b) * 12;
t = h + 19;
v = 20 - b;
q = w / t - v;




%% ____________________
%% FORMATTED TEXT DISPLAYS
fprintf("q = %0.2f\n",q);
%function[] = sampleFN(b, h, d) 

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



