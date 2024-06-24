%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Script for A08 Problem 2: MATLAB Skills - FOR Loop
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
M = 7;
N = 2;
S = 6;
Iterations = 0;
Z = [20, 17, 14, 30, 25, 11, 18, 10, 20, 26];
NumZ = 10;
%% ____________________
%% FOR LOOP
for Z = [20, 17, 14, 30, 25, 11, 18, 10, 20, 26]
    if Iterations <= NumZ
        T = Z * N;
        V = (N - Z) * M;
        S = T + V - S;
        Iterations = Iterations + 1;
    else
        fprintf('Iterations = %0.0f\n S = %0.0f\n', Iterations, S)    
    end
end
fprintf('Iterations = %0.0f\n S = %0.0f\n', Iterations, S)




%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.