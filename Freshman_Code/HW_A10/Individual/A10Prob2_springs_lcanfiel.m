function [spring_s] = A10Prob2_springs_lcanfiel(total_m,body_length,scaled_l)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: Given the total mass of the body, the length of the
% body sections and the center of mass locations this program calculates
% the spring stiffness constants for the springs
%
% Function Call:
% [spring_s] = A10Prob2_springs_lcanfiel(total_m,[body_length],[scaled_l])
%
% Input Arguments:
% total mass of the body: total_m (kg)
% length of body sections: body_length (m)
% scaled lengths: scaled_l (m)
%
% Output Arguments
% the spring stiffness constants for the springs: spring_s (N/m)
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
l_s = body_length(1,1);
l_t = body_length(1,2);
l_h = body_length(1,3);
d_s = scaled_l(1,1);
d_t = scaled_l(1,2);
d_h = scaled_l(1,3);
g = 9.8; 
d = 0.75; 
%% ____________________
%% CALCULATIONS
k = (total_m * g) / d; 
k1 = (k * d_s) / (l_s - d_s);
k2 = k1;
k3 = (k * d_t) / (l_t - d_t);
spring_s = [k,k1,k2,k3];

%% ____________________
%% TEXT DISPLAYS


%% ____________________
%% RESULTS



%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.

