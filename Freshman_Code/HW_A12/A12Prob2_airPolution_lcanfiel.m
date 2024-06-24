function [] = A12Prob2_airPolution_lcanfiel()
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program analyzes two sets of data one being CO2 data and the other being 
% SF6 data and performs linear regression on both of them and graphs both 
% sets of data on two different figures
%
% Function Call:
% function [] = A12Prob2_airPolution_lcanfiel()
%
% Input Arguments:
% There are no inputs
%
% Output Arguments:
% There are no outputs
%
% Assignment Information
%   Assignment:     A12, Problem 2
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        0l7-29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Kasin Mongkonrattanachai, kmongon@purdue.edu
% Faaiz Memon, fmemon@purdue.edu Bennett Twitmyer, btwitmye@purdue.edu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
data_co_2 = readmatrix('Data_NOAA_ESRL_co2_trend_1980-2020.csv');
data_sf_6 = readmatrix('Data_NOAA_ESRL_sf6_trend_1997-2020.csv');
co_x = data_co_2(:,3);
co_y = data_co_2(:,4);
sf_x = data_sf_6(:,3);
sf_y = data_sf_6(:,4);

%% ____________________
%% CALCULATIONS
% Finds the coefficients for the linear equation of each set of data
coeffs_co = polyfit(co_x,co_y,1);
coeffs_sf = polyfit(sf_x,sf_y,1);


%% ____________________
%% PREDICTION CALCULATIONS
% Calculates the predicted values of each set of data
y_model_co = coeffs_co(1) * co_x + coeffs_co(2);
y_model_sf = coeffs_sf(1) * sf_x + coeffs_sf(2);

% Calculates SSE
sse_co = sum((co_y - y_model_co).^2);
sse_sf = sum((sf_y - y_model_sf).^2);

% Calculates SST
sst_co = sum((co_y - mean(co_y)).^2);
sst_sf = sum((sf_y - mean(sf_y)).^2);

%Calculates R-squared
r_square_co = 1 - (sse_co / sst_co);
r_square_sf = 1 - (sse_sf / sst_sf);

%% ____________________
%% FORMATTED TEXT & FIGURE DISPLAYS

fprintf("Linear Model Equation for CO_2\n Average CO2(ppm) = %0.3f(decimal year) + %0.3f\n", coeffs_co(1),coeffs_co(2))
fprintf("\nLinear Model Equation for SF_6\n Average SF6(ppt) = %0.3f(decimal year) + %0.3f\n", coeffs_sf(1),coeffs_sf(2))
fprintf("\nSSE for CO2 = %0.3f\n", sse_co)
fprintf("SSE for SF6 = %0.3f\n", sse_sf)
fprintf("\nSST for CO2 = %0.3f\n", sst_co)
fprintf("SST for SF6 = %0.3f\n", sst_sf)
fprintf("\nr^2 for CO2 = %0.3f\n", r_square_co)
fprintf("r^2 for SF6 = %0.3f\n", r_square_sf)

subplot(2,2,1)
plot(co_x,co_y,'bs')
title('Decimal Years vs. Average CO2 Emissions')
xlabel("Decimal Years")
ylabel("Average CO2 (ppm)")
grid on 
hold on 
plot(co_x,y_model_co)
legend('CO2 Data', 'Trendline',"Location",'best')

subplot(2,2,3)
plot(sf_x,sf_y,'go')
title('Decimal Years vs. Average SF6 emissions')
xlabel("Decimal Years")
ylabel("Average SF6 (ppt)")
grid on 
hold on 
plot(sf_x,y_model_sf)
legend('SF6 Data', 'Trendline',"Location",'best')
%% ____________________
%% RESULTS
% A12Prob2_airPolution_lcanfiel
% Linear Model Equation for CO_2
%  Average CO2(ppm) = 1.810(decimal year) + -3249.916
%
% Linear Model Equation for SF_6
%  Average SF6(ppt) = 0.276(decimal year) + -546.986

% SSE for CO2 = 3320.555
% SSE for SF6 = 8.508

% SST for CO2 = 227784.780
% SST for SF6 = 973.750

% r^2 for CO2 = 0.985
% r^2 for SF6 = 0.991

%% ____________________
%% ANALYSIS

%% -- Q1
% Yes, we can draw a conclusion about the accuracy of the data
% measurements. The r^2 values in both sets of data are above 0.98 meaning
% that over 98% of the variation in both data sets can be explained by
% their linear equation models so we can conclude that the data measured
% was very accurate.

%% -- Q2
% The linear model for the SF6 data set best explains the variation that
% exists in the data. The r^2 value for the SF6 data set is 0.991 which
% means that roughly 99% of the variation in the dependent variable can be 
% explained by its linear model. The r^2 value for the CO2 data set is
% 0.985 which means that roughly 98.5 of the variation in the dependent
% variable can be explained by its linear model. This tells us that the
% linear model for the SF6 data explains the variation in the data a little
% bit better than the linear model for the CO2 data/.

%% -- Q3
% The CO2 level at year 1950.0 is 279.584(ppm)
% The CO2 level at year 2000.0 is 370.084(ppm)
% The CO2 level at year 2050.0 is 460.584(ppm)
% The first two predictions have decimal year values that are within the 
% range of decimal year values in the data set so the predictions are accurate.
% The third prediction does not have a decimal year value within the data
% set so we're extraploating outside of the given data, but the predicted
% value appears to follow the general trend of the graph so I believe it's
% fairly accurate.

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



