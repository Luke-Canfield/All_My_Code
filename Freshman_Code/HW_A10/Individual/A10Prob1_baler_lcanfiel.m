function [max_h, x_dist] = A10Prob1_baler_lcanfiel(v_o,theta)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: This program accepts finds the maximum height of the 
% hay bale (m) and the horizontal distance at the maximum height
%
% Function Call:
% [max_h, x_dist] = A10Prob1_baler_lcanfiel(v_o,theta);
%
% Input Arguments
% initial velocity of the hay bale: v_o (m/s)
% launch angle of the hay bale: theta (degrees)
%
% Output Arguments
% the maximum height of the bale: max_h (m)
% the horizontal distance at the maximum height: x_dist (m)
%
% Assignment Information
%   Assignment:     A10, Problem 1
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        0L7-29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Kasin Mongkonrattanachai, kmongon@purdue.edu
%Faaiz Memon, fmemon@purdue.edu   Bennett Twitmyer, btwitmye@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
% t = time since the hay bale was ejected
g = 9.8; % gravity constant

%% ____________________
%% CALCULATIONS
if (v_o < 9.5 || v_o > 13.25) 
    error("The intitial velocity input is invalid");
elseif (theta < 30 || theta > 60)
    error("The launch angle input is invalid");
end

t = (v_o * sind(theta)) / g; %calculates the time since the bale was ejected
x_dist = (v_o * cosd(theta)) * t; %calculates the horizontal distance 
max_h = 1.25 + ((v_o * sind(theta)) * t) - (0.5 * g * t^2); %calculates max height

%% ____________________
%% RESULTS
% Test Case #1
% >> [max_h, x_dist] = A10Prob1_baler_lcanfiel(15,35)
% Error using A10Prob1_baler_lcanfiel (line 37)
% The intitial velocity input is invalid
% 
% Test Case #2
% >> [max_h, x_dist] = A10Prob1_baler_lcanfiel(10,65)
% Error using A10Prob1_baler_lcanfiel (line 39)
% The launch angle input is invalid
%
% Test Case #3
% [max_h, x_dist] = A10Prob1_baler_lcanfiel(11.4,45)
%
% max_h =
%
%   4.5653
%
%
% x_dist =
%
%    6.6306
%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



