%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program analyzes a data matrix that contains different types of data
% and answers five specified questions using logical operators.
%
% Assignment Information
%   Assignment:     A06, Problem 3
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
L_data = readmatrix('Data_global_landslide.csv'); %Landslide matrix
L_year = L_data(:,1); %Landslide year column of data
L_category = L_data(:,2); %Landslide category column of data
L_trigger = L_data(:,3); %Landslide trigger column of data
L_size = L_data(:,4); %Landslide size column of data
L_fatalities = L_data(:,5); %Landslide fatalities column of data
L_injuries = L_data(:,6); %Landslide injuries column of data
L_longitude = L_data(:,7); %Landslide longitude column of data
L_latitude = L_data(:,8); %Landslide latitude column of data

%% ____________________
%% CALCULATIONS
question_1 = sum(L_category == 2 & L_trigger ~= 30) + ...
   sum(L_trigger == 30 & L_category ~= 2);
%Calculates how many landslides occurred that were categorized as 
%mudslide whose landslide trigger was not downpour, or landslides that 
%were triggered by downpour but were not categorized as mudslide.

question2 = find(L_category == 3);
question_2 = mean(L_latitude(question2,:));
%Calculates the average latitude of landslides categorized as snow
%avalanche.

question_3 = sum(L_fatalities > 50 & L_latitude > 0 & L_longitude > 0) + ...
sum(L_fatalities > 50 & L_longitude < 0 & L_latitude < 0);
%Calculates the number of landslides that had fatalities greater than 50
%that occured within latitudes greater than 0 or longitudes less than 0 but
%not both.

question_4 = sum(L_category < 3 & L_trigger > 30 & L_size >= 200 & ...
    L_latitude > 0);
%Calculates the number of mudslides and landslides that occurred due to
%snow fall or snow melt that had landslide sizes that were at least medium
%with latitudes aboe the equator.

question5_num = sum(L_size == 200 & L_category == 3 & L_latitude > 19.5... 
 & L_latitude < 64.85 & L_longitude < 0);
question5_location = find(L_size == 200 & L_category == 3 & L_latitude > ...
   19.5 & L_latitude < 64.85 & L_longitude < 0);
question5_year = (L_year(question5_location,:));
%Calculates the number of medium sized snow avalnaches in the USA and which
%years they occured in.


%% ____________________
%% FORMATTED TEXT DISPLAYS
fprintf(['\nThe number of landslides that were categorized as “mudslide” and ',... 
'downpour, or landslides that were triggered by “downpour”\n but were not',...
'categorized as “mudslide" is %d'],question_1)

fprintf(['\n\nThe average latitude of landlsides categorized as snow',... 
'avalanche is %.2f\n'],question_2)

fprintf(['\nThe number of cases involved any type of landslide with',...
'fatalities greater than 50 that occurred within\n latitudes greater than',... 
'0 or longitudes less than 0 but not both is %d'], question_3)

fprintf(['\n\nThe number of “mudslides” and “landslides” occurred due to ',...
'“snow fall or snow melt” that had landslide\n sizes that were at least ',...
'“medium” with latitudes above the equator is %d'], question_4)

fprintf(['\n\nThe number of year(s) were there were “medium” sized landslide ',...
'categories of “snow avalanche” in the USA is %d'], question5_num)
fprintf(['\nThe year(s) they happened were %d\n'], question5_year)
    
%% ____________________
%% RESULTS
%The number of landslides that were categorized as “mudslide” and downpour,
%or landslides that were triggered by “downpour”but were notcategorized as
%“mudslide" is 3795

%The average latitude of landlsides categorized as snowavalanche is 30.98

%The number of cases involved any type of landslide withfatalities greater 
%than 50 that occurred within latitudes greater than0 or longitudes less 
%than 0 but not both is 14

%The number of “mudslides” and “landslides” occurred due to “snow fall or
%snow melt” that had landslide sizes that were at least “medium” with
%latitudes above the equator is 59

%The number of year(s) were there were “medium” sized landslide categories
%of “snow avalanche” in the USA is 1 The year(s) they happened were 2017 


%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.