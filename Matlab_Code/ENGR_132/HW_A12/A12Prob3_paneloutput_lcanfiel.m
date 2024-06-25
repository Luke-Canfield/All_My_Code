function [electrical_output] = A12Prob3_paneloutput_lcanfiel(peak_hours)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program analyes peak sunlight time data and determines the
% least-squares model for the data. Once the least-squares model is
% calculated the function will take the sunlight input and place it in the
% model equation to find the predicted electrical output
%
% Function Call:
% function [electrical_output] = A12Prob3_paneloutput_lcanfiel(peak_hours)
%
% Input Arguments:
% value for peak sun hours: peak_hours
%
% Output Arguments:
% predicted electrical output: electrical_output
%
% Assignment Information
%   Assignment:     A12, Problem 3
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
s_panel_data = readmatrix('Data_panelX5_output_measurements.csv');
peak_sun = s_panel_data(:,1);
e_output = s_panel_data(:,2);


%% ____________________
%% REGRESSION CALCULATIONS
coeffs = polyfit(peak_sun,e_output,1);


%% ____________________
%% REGRESSION TEXT & FIGURE DISPLAYS
y_model = coeffs(1) * peak_sun + coeffs(2);

% Calculates SSE
sse = sum((e_output - y_model).^2);

% Calculates SST
sst = sum((e_output - mean(e_output)).^2);

%Calculates R-squared
r_square = 1 - (sse / sst);

plot(peak_sun,e_output,'bs')
title('Sunlight vs. Electrical Output')
xlabel("Sun Peak Hours (hr)")
ylabel("Electrical Output (kWh)")
grid on 
hold on
plot(peak_sun,y_model)
legend('Sunlight Data','Trendline',"Location",'best')
axis([1 8 0 18])
%% ____________________
%% PREDICTION CALCULATIONS AND DISPLAY
electrical_output = coeffs(1) * peak_hours + coeffs(2);
if electrical_output < 0
    error("The electrical output cannot be less than zero. Try selecting a larger value for the input");
else
    electrical_ouput = electrical_output * 1;
end

fprintf("Linear Model Equation for Electricity Production\n Electrical output(kWh) = %0.3f(sunlight(hr)) + %0.3f\n", coeffs(1),coeffs(2))
fprintf("\nSSE = %0.3f\n", sse)
fprintf("SST = %0.3f\n", sst)
fprintf("r^2 = %0.3f\n", r_square)

%% ____________________
%% RESULTS
% [electrical_output] = A12Prob3_paneloutput_lcanfiel(4.8)
% Linear Model Equation for Electricity Production
%  Electrical output(kWh) = 2.722(sunlight(hr)) + -5.048

% SSE = 44.385
% SST = 740.307
% r^2 = 0.940

% electrical_output =

%     8.0186

% [electrical_output] = A12Prob3_paneloutput_lcanfiel(7.5)
% Linear Model Equation for Electricity Production
%  Electrical output(kWh) = 2.722(sunlight(hr)) + -5.048

% SSE = 44.385
% SST = 740.307
% r^2 = 0.940

% electrical_output =

%   15.3684

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



