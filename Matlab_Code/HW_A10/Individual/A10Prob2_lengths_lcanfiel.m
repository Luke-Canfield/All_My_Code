function [total_m, scaled_l] = A10Prob2_lengths_lcanfiel(body_mass,...
    body_length,location_c)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: This program calculates the total mass of the body 
% and calculates the scaled lengths
%
% Function Call
% [total_m, scaled_l] = A10Prob2_lengths_lcanfiel([body_mass],...
% [body_length],[location_c])
%
% Input Arguments
% the mass of the body sections: body_mass (kg) 
% the length of the body sections: body_length (m)
% the center_of_mass locatoins of body sections: location_c (m)
%
% Output Arguments
% the scaled lengths: scaled_l (m)
% total mass of the body: total_m (kg)
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
bm_1 = body_mass(1,1);
bm_2 = body_mass(1,2);
bm_3 = body_mass(1,3);
l_s = body_length(1,1);
l_t = body_length(1,2);
l_h = body_length(1,3);
c_s = location_c(1,1);
c_t = location_c(1,2);
c_h = location_c(1,3);
%% ____________________
%% CALCULATIONS
total_m = sum(body_mass); %calculates total mass of the body 
d_s = (1 / total_m) * (bm_2 * l_s + bm_3 * l_s + bm_1 * c_s);
d_t = (1 / total_m) * (bm_3 * l_t + bm_2 * c_t);
d_h = (1 / total_m) * (bm_3 * c_h);
scaled_l = [d_s,d_t,d_h];

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



