%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132
% Program Description:
% workout plan following the specifications needed
%
% Assignment Information
%   Assignment:     A08, Problem 4
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        Team 29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% ____________________
%% INITIALIZATION
rest_day = 0; %exercise for 0 minutes
sports_day = 90; %exercise for 90 minutes
run_1 = 30; %exercise for 30 minutes
run_2 = 45; %exercise for 45 minutes
%total_d = number of days in schedule
%s_day = sports day during week specified by user
%r_day = rest day during week specified by user
% a = number of weeks
% N = array of schedule

prompt = 'How many days are in the exercise schedule? ';
total_d = input(prompt);

prompt1 = 'What day of the week will be the sports day(assume Monday is Day 1, Tuesday is Day 2, etc.)? ';
s_day = input(prompt1);

prompt2 = 'What day of the week will be the rest day (using the same day numbers as above)? ';
r_day = input(prompt2);

%% ____________________
%% CALCULATIONS
a = total_d / 7;
N(a,7) = 0;
W(1,7) = 0;
str = string(W);
for i = 7
    str(1,1) = 'Monday';
    str(1,2) = 'Tuesday';
    str(1,3) = 'Wednesday';
    str(1,4) = 'Thursday';
    str(1,5) = 'Friday';
    str(1,6) = 'Saturday';
    str(1,7) = 'Sunday';
end

for index = total_d
    N(:,1) = 30;
    N(:,3) = 30;
    N(:,5) = 30;
    N(:,7) = 30;
    N(:,2) = 45;
    N(:,4) = 45;
    N(:,6) = 45;
    N(:,s_day) = sports_day;
    N(:,r_day) = rest_day;
end

str1 = string(N);
stacked = [str; str1];

    

%% ____________________
%% FORMATTED TEXT DISPLAY
disp(stacked);



%% ____________________
%% RESULTS
%How many days are in the exercise schedule? 35
%What day of the week will be the sports day(assume Monday is Day 1, Tuesday is Day 2, etc.)? 4
%What day of the week will be the rest day (using the same day numbers as above)? 5
%    "Monday"    "Tuesday"    "Wednesday"    "Thursday"    "Friday"    "Saturday"    "Sunday"
%    "30"        "45"         "30"           "90"          "0"         "45"          "30"    
%    "30"        "45"         "30"           "90"          "0"         "45"          "30"    
%    "30"        "45"         "30"           "90"          "0"         "45"          "30"    
%    "30"        "45"         "30"           "90"          "0"         "45"          "30"    
%    "30"        "45"         "30"           "90"          "0"         "45"          "30"    
%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am % submitting is my own original work.