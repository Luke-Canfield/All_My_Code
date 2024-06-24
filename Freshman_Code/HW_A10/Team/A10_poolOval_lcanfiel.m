function [volume] = A10_poolOval_lcanfiel(surface_r, shallow_D,...
    deep_D);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: Finds the volume of the pool which has an oval shape
% and a fully slanted floor
%
% Function Call
% funcion[volume] = A10_poolOval_lcanfiel(surface_r, shallowDepth...
%    deepDepth);
%
% Input Arguments
% total surface radius of the pool: surface_r (feet)
% depth of shallow section of the pool: shallow_D (feet)
% depth of deep section of the pool: deep_D (feet)
%
% Output Arguments
% total volume of the pool: volume (ft^3)
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


%% ____________________
%% CALCULATIONS
if (surface_r < 0 || shallow_D < 0 || deep_D < 0)
    error("One or more input values are negative");
end

V_shallow = ((surface_r^2) * PI) * shallow_D;
height = deep_D - shallow_D;
V_deep = (1 / 3) * PI * height * (surface_r^2);
volume = V_shallow + V_deep;
%% ____________________
%% FORMATTED TEXT/FIGURE DISPLAYS


%% ____________________
%% COMMAND WINDOW OUTPUT


%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



