%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Script for A11 Problem 2: MATLAB Skills - Nested Loops
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% ____________________
%% FLOWCHART TRANSLATION
a = 0;
b = 9;
count_outer = 0;
total_iterations = 0;
sum_ab = a + b;

for index = 1:10
    if sum_ab < 1000
        count_outer = count_outer + 1;
        a = a + 1;
        c = 4;
        while c <= 17
            a = 2 * a + c;
            b = 5 * c;
            sum_ab = a + b;
            total_iterations = total_iterations + 1;
            c = c + 5;
        end
    end
end

fprintf("The number of outer loop iterations: %0.0f\n",count_outer);
fprintf("The number of total_iterations: %0.0f\n",total_iterations);
fprintf("The final value of sum_ab: %0.0f\n",sum_ab);



%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.