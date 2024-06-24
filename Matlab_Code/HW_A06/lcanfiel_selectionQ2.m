%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
% This program displays the expected state of a copper-nickel alloy 
% when given the alloy’s composition and temperature.
%
% Assignment Information
%   Assignment:     In-Class Activity Class ##
%   Author:         Name, login@purdue.edu
%   Team ID:        ###-##
% This is an in-class activity. It is expected that you worked with your
% team.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
A = 128;


%% ____________________
%% SELECTION STRUCTURE
if A <= -17 | A > 373
    A = (A / 11);
    disp(A);
elseif A < 16
    A = (A * 2);
    disp(A);
elseif A > 103 & A < 127
    A = (A * 9);
    disp(A);
elseif A < 33 | A >= 245
    A = (A - 99);
    disp(A);
else
    disp("A is invalid")
end


%% ____________________
%% TEST CASES RESULTS

% Test Case: In the L region of the diagram
    % Temperature chosen: [fill in your test case value]
    % Percent Nickel chosen: [fill in your test case value]
    % MATLAB Output: [copy and paste your MATLAB command window output as comments]

% Test Case: In the L+α region of the diagram
    % Temperature chosen: [fill in your test case value]
    % Percent Nickel chosen: [fill in your test case value]
    % MATLAB Output: [copy and paste your MATLAB command window output as comments]
    
% Test Case: In the α regionof the diagram
    % Temperature chosen: [fill in your test case value]
    % Percent Nickel chosen: [fill in your test case value]
    % MATLAB Output: [copy and paste your MATLAB command window output as comments]
    
% Test Case: Invalid Low Temperature
    % Temperature chosen: [fill in your test case value]
    % Percent Nickel chosen: [fill in your test case value]
    % MATLAB Output: [copy and paste your MATLAB command window output as comments]

% Test Case: Invalid High Temperature
    % Temperature chosen: [fill in your test case value]
    % Percent Nickel chosen: [fill in your test case value]
    % MATLAB Output: [copy and paste your MATLAB command window output as comments]
    
 % Test Case: Invalid Low % Nickel
    % Temperature chosen: [fill in your test case value]
    % Percent Nickel chosen: [fill in your test case value]
    % MATLAB Output: [copy and paste your MATLAB command window output as comments]

% Test Case: Invalid High % Nickel
    % Temperature chosen: [fill in your test case value]
    % Percent Nickel chosen: [fill in your test case value]
    % MATLAB Output: [copy and paste your MATLAB command window output as comments]
    