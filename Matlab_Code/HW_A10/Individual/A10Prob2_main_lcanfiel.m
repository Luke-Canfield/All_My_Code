function [] = A10Prob2_main_lcanfiel()
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program calculates the L(ci) values and displays the four spring 
% constants that are calculated within the subfunctions
%
% Function Call:
% function [] = A10Prob2_main_lcanfiel()
%
% Input Arguments:
% This function accepts no inputs
%
% Output Arguments:
% This function returns no outputs
%
% Assignment Information
%   Assignment:     A10, Problem 2
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        0L7-29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Kasin Mongkonrattanachai, kmongon@purdue.edu
% Faaiz Memon, fmemon@purdue.edu Bennett Twitmyer, btwitmye@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
body_length = [0.421,0.432,0.8];
body_mass = [3.1,7.39,24.13];
location_c = [0.55 0.59 0.41];

c1 = location_c(1,1);
c2 = location_c(1,2);
c3 = location_c(1,3);

b1 = body_length(1,1);
b2 = body_length(1,2);
b3 = body_length(1,3);
%% ____________________
%% CALCULATIONS
li_a = c1 * b1;
li_b = c2 * b2;
li_c = c3 * b3;
li_values = [li_a,li_b,li_c];

[total_m, scaled_l] = A10Prob2_lengths_lcanfiel(body_mass,...
    body_length,li_values);

[spring_s] = A10Prob2_springs_lcanfiel(total_m,body_length,scaled_l);

k = spring_s(1,1);
k1 = spring_s(1,2);
k2 = spring_s(1,3);
k3 = spring_s(1,4);

%% ____________________
%% TEXT DISPLAYS
fprintf("The spring constants are: \n");
fprintf("K1 = %0.2f (N/m)\n", k);
fprintf("K2 = %0.2f (N/m)\n", k1);
fprintf("K3 = %0.2f (N/m)\n", k2);
fprintf("K4 = %0.2f (N/m)\n", k3);

%% ____________________
%% RESULTS
% >> A10Prob2_main_lcanfiel
% The spring constants are: 
% K1 = 452.37
% K2 = 10774.14
% K3 = 10774.14
% K4 = 2102.48


%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



