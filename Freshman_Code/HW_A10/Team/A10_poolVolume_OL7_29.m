function A10_poolVolume_OL7_29 (pool_type)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
% This is the main function for Problem 1 of the A10 Team component. It
% accepts the pool type ("Standard," "Ramp," "Round," or "Oval") and prints
% the volume of that pool type using manufacturer dimensions and dedicated
% sub-functions.
%
% Function Call
% A10_poolVolume_OL7_29(pool_type)
%
% Input Arguments
% type of pool: pool_type (string category)
%
% Output Arguments
% none
%
% Assignment Information
%   Assignment:     A10, Problem 1, TEAM
%   Authors:        Faaiz Memon, fmemon@purdue.edu, Kasin, kmongon@purdue.edu
%   Team ID:        OL7-29
%   Academic Integrity:
%     [X] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Luke Canfield, lcanfiel@purdue.edu
%                          Bennett Twitmeyer, btwitmye@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
Data_val = readmatrix('Data_manufacturer_testDims');
L1 = Data_val(:,2); % Data value for L1 for all pool type
L2 = Data_val(:,3); % Data value for L2 for all pool type
Ds = Data_val(:,4); % Data value for Ds for all pool type
Dd = Data_val(:,5); % Data value for Dd for all pool type


%% ____________________
%% CALCULATIONS
% Standard pool (Note we reference linear index position 1 for the standard pool type)
standard_vol = A10_poolStandard_kmongkon(L1(1), L2(1), Ds(1), Dd(1));
% Ramp pool
ramp_vol = A10_poolRamp_fmemon(L1(2), L2(2), Ds(2), Dd(2));
% Round pool
round_vol = A10_poolRound_btwitmye(L1(3), L2(3), Ds(3), Dd(3));
% Oval pool
oval_vol = A10_poolOval_lcanfiel(L1(4), L2(4), Ds(4), Dd(4));
    
    
    

%% ____________________
%% FORMATTED TEXT/FIGURE DISPLAYS
if pool_type == "Standard"
    fprintf("Standard pool with volume of %.2f [m^3]\n",standard_vol);
elseif pool_type == "Ramp"
    fprintf("Ramp pool with volume of %.2f [m^3]\n",ramp_vol);
elseif pool_type == "Round"
    fprintf("Round pool with volume of %.2f [m^3]\n",round_vol);
elseif pool_type == "Oval"
    fprintf("Oval pool with volume of %.2f [m^3]\n",oval_vol);
else
    error("Input for pool type does not match one of the available shapes");
end

%% ____________________
%% RESULTS

% -- Standard Pool
% A10_poolVolume_OL7_29("Standard")
% Standard pool with volume of 34000.00 [m^3]

% -- Ramp Pool
% A10_poolVolume_OL7_29("Ramp")
% Ramp pool with volume of 31500.00 [m^3]

% -- Round Pool
% A10_poolVolume_OL7_29("Round")
% Round pool with volume of 39230.64 [m^3]

% -- Oval Pool (only used by teams with 4 members)
% A10_poolVolume_OL7_29("Oval")
% 


%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



