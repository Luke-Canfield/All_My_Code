function [volume] = A10_poolRamp_fmemon(surfaceLength, surfaceWidth, ...
    shallowDepth, deepDepth);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
% This is a sub-function for A10_poolVolume, dedicated to the ramp pool
% design option. It accepts the surface length, surface width, shallow end
% depth, and deep end depth, all in feet, to calculate the total volume.
%
% Function Call
% function [volume] = A10_poolRamp_fmemon(surfaceLength, surfaceWidth, ...
%    shallowDepth, deepDepth);
%
% Input Arguments
% total surface length of the pool: surfaceLength (feet)
% surface width of the pool: surfaceWidth (feet)
% depth of shallow section of pool: shallowDepth (feet)
% depth of deep section of pool: deepDepth (feet)
%
% Output Arguments
% total volume of the pool: volume (feet^3)
%
% Assignment Information
%   Assignment:     A10, Problem 1 (Team)
%   Author:         Faaiz Memon, fmemon@purdue.edu
%   Team ID:        OL7-29
%   Academic Integrity:
%     [X] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%   Peers I worked with: Kasin Mongkonrattanachai, kmongkon@purdue.edu
%                        Luke Canfield, lcanfiel@purdue.edu
%                        Bennett Twitmeyer, btwitmye@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION


%% ____________________
%% CALCULATIONS
if(surfaceLength < 0 || surfaceWidth < 0 || shallowDepth < 0 || deepDepth < 0)
    error("One or more input values were negative.");
end

section1Volume = 0.5 * (surfaceLength / 3) * shallowDepth * surfaceWidth;
section2Volume = (surfaceLength / 3) * shallowDepth * surfaceWidth;
section3Volume = (0.5 * (shallowDepth + deepDepth)) * (surfaceLength/3) ...
    * surfaceWidth;
volume = section1Volume + section2Volume + section3Volume;
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



