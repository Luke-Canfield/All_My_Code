%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program given a booking number, an economy class, and some number of 
% users will sort a passenger or passengers into their designated 
% seating assignment on an airplane
%
% Assignment Information
%   Assignment:     A06, Problem 4
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        Team 29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Kasin Mongkonrattanachai, kmongkon@purdue.edu
%                          Bennett Twitmeyer, btwitmye@purdue.edu 
%                          Faaiz Memon, fmemon@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% ____________________
%% INITIALIZATION
booking_numbers = readmatrix('Data_booking_numbers.txt'); %list of 100 bookings 
user_booking = 13925866; %user booking number
econ_class = 1; %economy class of the ticket (2 = basic, 1 = premium)
number_users = sum(booking_numbers == 13925866); %number of users with booking


%% ____________________
%% CALCULATIONS & DISPLAYS
if econ_class == 1 & number_users == 1
    fprintf('Seat Assignment: Window, %d\n', user_booking)
elseif econ_class == 2 & number_users == 1
    fprintf('Seat Assignment: Aisle, %d\n', user_booking)
elseif econ_class == 2 | econ_class == 1 & number_users == 2 | number_users == 3
    fprintf('Seat Assignment: One side row, %d\n', user_booking)
elseif econ_class == 1 & number_users == 4
    fprintf(['Seat Assignment: One side row plus aisle seat on opposite ',...
        'side, %d\n'], user_booking)
elseif econ_class == 2 & number_users == 4
    fprintf(['Seat Assignment: One side row plus aisle seat in front of',...
        'the full side, %d\n'], user_booking)
elseif econ_class == 1 | econ_class == 2 & number_users == 5 | number_users == 6
    fprintf('Seat Assignment: One full row, %d\n', user_booking)
elseif econ_class > 2 | econ_class < 1 & number_users > 0
    fprintf('Invalid economy class\n')
else
    fprintf('Invalid booking number\n')
end


%% ____________________
%% RESULTS

% Test Case 1
% Seat Assignment: Aisle, 13845360

% Test Case 2
% Seat Assignment: One full row, 17248113

% Test Case 3
% Seat Assignment: One side row, 17657472

% Test Case 4
% Seat Assignment: Aisle, 18276759

% Test Case 5
% Seat Assignment: One side row plus aisle seat on opposite side, 12774978

% Test Case 6
% Seat Assignment: One side row, 21004657

% Test Case 7
% Seat Assignment: One side row, 11174805

% Test Case 8
% Seat Assignment: Window, 13925866


%% ____________________
%% ANALYSIS

% -- Q1
% Each condition in the flowchart is not tested at least once. The
% conditions that are not tested are the booking for 4 passengers in basic
% economy, the condition of booking number being valid and the economy class
% being invalid, and the invalid booking number condition.


%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.