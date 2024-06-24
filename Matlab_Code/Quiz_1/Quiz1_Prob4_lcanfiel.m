%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program imports a set of data and analyzes the fifth test within the
% data. It takes the applied force used in the set of data and places it in a
% linear fit and quadratic fit equation to see which equation is a better
% fit for the data.
%
% Assignment Information
%   Assignment:     Exam 1, Problem 4
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        Team 29
%   Academic Integrity:
%     [] I worked alone on this problem and only used resourses
%        that meet academic integrity expectations.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% ____________________
%% INITIALIZATION
Test_data = readmatrix('Quiz1_Prob4_data_32342067.csv'); %Test Matrix
Test5_data = Test_data(:,6); %Test5 column of data
Applied_force = Test_data(:,1); %Applied force column of data
% y1 = measured deflection for each force for linear fit
% y2 = measured deflection for each force for quadratic fit
n = 100;
%% ____________________
%% CALCULATIONS
y1 = 0.918 * Applied_force + (-16.1);
y2 = 0.00857 * Applied_force.^2 + (0.0973 * Applied_force) + (-2.13); 
a = mean(y1,'all');
b = mean(y2,'all');
c = (y1 - a).^2;
d = mean(c);
e = (y2 - b).^2;
f = mean(e);
SSE_1 = (1/n) * sqrt(d);
SSE_2 = (1/n) * sqrt(f);

if SSE_1 > SSE_2
    fprintf("SSE for the linear model: %0.3f\n", SSE_1);
    fprintf("SSE for the quadratic model: %0.3f\n", SSE_2);
    fprintf("The Quadratic fit is better.");
else
    fprintf("SSE for the linear model: %0.3f\n", SSE_1);
    fprintf("SSE for the quadratic model: %0.3f\n", SSE_2);
    fprintf("The Linear fit is better.\n");
end

%% ____________________
%% FORMATTED FIGURE DISPLAYS
subplot(2,2,1)
plot(y1,Applied_force, 'ro')
title("Original Data vs. Linear Model")
xlabel('Applied Force (N)')
ylabel('Deflection (mm)')
grid on
axis([1 80 0 100])

hold on
% Plots Linear Fit data
plot(Test5_data,Applied_force, 'bd')
legend('LinearFit vs Force', 'Test5 vs Force',"Location",'best')
hold off 
% Plots Test5 data

subplot(2,2,3)
plot(y2,Applied_force, 'ro')
title("Original Data vs. Quadratic Model")
xlabel('Applied Force (N)')
ylabel('Deflection (mm)')
grid on
axis([1 80 0 100])

hold on
% Plots Linear Fit data
plot(Test5_data,Applied_force, 'bd')
legend('QuadraticFit vs Force', 'Test5 vs Force',"Location",'best')
hold off 

%% ____________________
%% FORMATTED TEXT DISPLAYS
%SSE for the linear model: 0.265
%SSE for the quadratic model: 0.285
%The Linear fit is better.


%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.