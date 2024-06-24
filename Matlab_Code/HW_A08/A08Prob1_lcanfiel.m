%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Script for A08 Problem 1: MATLAB Skills - WHILE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
A = 97;
B = 10; 
Iterations = 0;
%% ____________________
%% WHILE LOOP
while A > 15 || B < 10240
    A = A * 0.8;
    B = B * 2;
    C = A * B;
    Iterations = Iterations + 1;
end
fprintf('Iterations = %0.0f\n C = %0.0f\n', Iterations, C)




%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.