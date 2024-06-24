%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
%
%
% Assignment Information
%   Assignment:     Exam 1, Problem 5
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        Team 29
%   Academic Integrity:
%     [] I worked alone on this problem and only used resourses
%        that meet academic integrity expectations.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% There is no INITIALIZATION section. The variable "tomato_gray" is already
% in your workspace. Use that variable in your calculations.

%% ____________________
%% CALCULATIONS
a = mean(tomato_gray,'all');
b = (tomato_gray - a)^2;
c = mean(b,'all');
d = c / 100;
std = sqrt(d);

if std < 0.054
    fprintf("Color standard deviation is: %0.3f\n",std);
    fprintf("Sell as whole fruit.\n");
elseif std >= 0.054 & std <= 0.059
    fprintf("Color standard deviation is %0.3f\n",std);
    fprintf("Sell for food processing.\n");
else
    fprintf("Color standard deviation is: %0.3f\n",std);
    fprintf("This tomato cannot be used for human consumption.\n");
end
fprintf("b: %0.3f\n", b)
%% ____________________
%% FORMATTED TEXT DISPLAYS
%Color standard deviation is: 0.201
%This tomato cannot be used for human consumption.


%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.