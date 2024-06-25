function [out1] = Spring2021_Q2_translate(in1, in2)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
%   Function template for A09 - Problem 2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
% in1 is first input
% in2 is second input
% out1 is the only output
in3 = in1 * in2; %calculates product of in1 and in2

%% ____________________
%% CALCULATIONS
if in1 < 20
        out1 = -11;
    elseif in2 < 1 || rem(in2,1) ~= 0
        out1 = -55;
else
    out1 = in1 + in2;
     
    if out1 < in3
        out1 = out1 * 2;
    else
        return
    end
end
    


%% ____________________
%% FORMATTED TEXT DISPLAYS



%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



