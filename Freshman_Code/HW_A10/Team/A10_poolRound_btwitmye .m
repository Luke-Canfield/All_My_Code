function [volume]= A10_poolRound_btwitmye(surfaceRad, bottomRad,...
    shallowDepth, deepDepth)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description - Finds the volume of a round pool with a flat bottom
% and sloping sides. 
%
% Function Call- 
% function[volume]= A10_poolRound_btwitmye(surfaceRad, bottomRad,...
%    shallowDepth, deepDepth);
%
% Input Arguments
% total surface radius of the pool: surfaceRad (feet)
% bottom radius of the pool: bottomRad (feet)
% depth of shallow section of pool: shallowDepth (feet)
% depth of deep section of pool: deepDepth (feet)
%
% Output Arguments
% total volume of pool - Volume (ft^3) 
%
% Assignment Information
%   Assignment:     A10, Problem 1
%   Author:         Bennett, btwitmye@purdue.edu
%   Team ID:        OL7-29
%  Academic Integrity:
%     [X] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%   Peers I worked with: Kasin Mongkonrattanachai, kmongkon@purdue.edu
%                        Luke Canfield, lcanfiel@purdue.edu
%                        Faaiz Memon, fmemon@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION


%% ____________________
%% CALCULATIONS
%Will return an error if one of the numbers is below 0.
if (surfaceRad < 0 || bottomRad < 0 || shallowDepth < 0 || deepDepth < 0)
 error("One or more input values were negative.");
end

%Calculating the volume of the pool with a multi part system
vshallow = (pi * (surfaceRad^2)) * shallowDepth;
deeph = deepDepth-shallowDepth;
vdeep = (1 / 3) * pi * deeph * (bottomRad^2 + bottomRad * surfaceRad + surfaceRad^2);
%Adding the final parts.
volume = vshallow + vdeep;

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



