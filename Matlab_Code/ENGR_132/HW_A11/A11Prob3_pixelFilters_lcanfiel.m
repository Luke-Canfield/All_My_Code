function [] = A11Prob3_pixelFilters_lcanfiel()
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program imports a data set and then changes all of the non-border
% values to the median of the surrounding squares 
%
% Function Call
% function [] = A11Prob3_pixelFilters_lcanfiel()
%
% Input Arguments
% This function accepts no inputs
%
% Output Arguments
% This function returns no outputs
%
% Assignment Information
%   Assignment:     A11, Problem 3
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        0L7-29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Kasin Mongkonrattanachai, kmongon@purdue.edu
% Faaiz Memon, fmemon@purdue.edu   Bennett Twitmyer, btwitmye@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
pixel_data = readmatrix('Data_pixels.csv');
Filter_1 = readmatrix('Data_pixels.csv');
Filter_2 = readmatrix('Data_pixels.csv');
Filter_3 = readmatrix('Data_pixels.csv');
[Nrows,Ncols] = size(pixel_data);
rows = Nrows - 1;
cols = Ncols - 1;

%% ____________________
%% CALCULATIONS

for col = 2:cols
    for row = 2:rows
        med_1 = median(Filter_1(row-1:row+1,col-1:col+1),'all');
        Filter_1(row,col) = med_1;
    end
end

for col = cols:-1:2
    for row = rows:-1:2
        med_2 = median(Filter_2(row-1:row+1,col-1:col+1),'all');
        Filter_2(row,col) = med_2;
    end
end

for row = 2:rows
    for col = 2:cols
        med_3 = median(Filter_3(row-1:row+1,col-1:col+1),'all');
        Filter_3(row,col) = med_3;
    end
end
%% ____________________
%% FORMATTED TEXT/FIGURE DISPLAYS
subplot(2,2,1);
heatmap(pixel_data);
title('Original Data')

subplot(2,2,2);
heatmap(Filter_2);
title('Filter #2')

subplot(2,2,3);
heatmap(Filter_1);
title('Filter #3')

subplot(2,2,4);
heatmap(Filter_3);
title('Filter #4')



%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



