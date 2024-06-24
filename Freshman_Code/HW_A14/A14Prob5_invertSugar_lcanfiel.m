%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program analyzes a set of sucrose data and performs non-linear
% regression on it
%
% Assignment Information
%   Assignment:     A14, Problem 5
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
cane_data = readmatrix('Data_sucroseInversion.csv');
time = cane_data(:,1);
sucrose = cane_data(:,2);

ln_time = log10(time);
ln_sucrose = log10(sucrose);
%% ____________________
%% DATA on SCALED PLOTS
subplot(2,2,1)
plot(time,sucrose,'bs')
title("Original Data")
xlabel("Time(min)")
ylabel("Sucrose(M)")
grid on 
hold on

subplot(2,2,2)
semilogx(time,sucrose,'ro')
title("Time vs. Sucrose")
xlabel("Log Time(min)")
ylabel("Sucrose(M)")

subplot(2,2,3)
semilogy(time,sucrose,'gs')
title("Time vs. Sucrose")
xlabel("Time(min)")
ylabel("Log Sucrose(M)")

subplot(2,2,4)
loglog(time,sucrose,'ys')
title("Time vs. Sucrose")
xlabel("Log Time(min)")
ylabel("Log Sucrose(M)")
grid off 
hold off

%% ____________________
%% LINEARIZATION CALCULATIONS
coeffs_1 = polyfit(ln_time, ln_sucrose,1);

linear_s = coeffs_1(1); 
linear_i = coeffs_1(2);
linear_m = linear_s * ln_time + linear_i;

%% ____________________
%% GENERAL MODEL CALCULATIONS
general_s = linear_s;
general_i = 10^(linear_i);
general_m = general_i * time.^ (general_s);


%% ____________________
%% LINEARIZATION FIGURE DISPLAY
figure(2)
plot(ln_time, ln_sucrose, "bd")
hold on
plot(ln_time, linear_m, "r-")
title('Linearized Data vs. Linear Model')
xlabel("Log10 Time(min)")
ylabel("Log10 Sucrose(M)")
legend("linearized data", "linear model","location", "best")
grid on 
hold off

%% ____________________
%% GENERAL MODEL FIGURE DISPLAY
figure(3)
plot(time, sucrose, "bs")
hold on
plot(time, general_m, "g-")
title('Original Data vs. General Model')
xlabel("Time(min)")
ylabel("Sucrose(M)")
legend("original data", "general model","location", "best")
grid on 
hold off

%% ____________________
%% ALL TEXT DISPLAYS
fprintf("Function Type: Exponential\n")
fprintf("Linearized model = %0.2f*(time)+%0.2f\n",linear_s,linear_i)
fprintf("General Model = %0.2f*(time).^%0.2f\n",general_i,general_s)
%% ____________________
%% ANALYSIS

% -- Text displays from Command Window
% Function Type: Exponential
% Linearized model = -0.90*(time)+0.17
% General Model = 1.49*(time).^-0.90

% -- Q1
% I chose the exponential model because when I scaled all of the axes the
% graph with the linear time data and log sucrose data displayed the most
% linear data out of the four graphs. This is why I chose an exponential
% model.

% -- Q2
% 1.49 *(12).^-0.90 = 0.159 M
% 1.49 *(36).^-0.90 = 0.059 M
% 1.49 *(72).^-0.90 = 0.032 M

% The predictions at 12 min and 36 min fall within the data presented on
% the graph and the values at each time stamp follow the general curve of
% the model. The prediction at 72 min falls outside of the data presented
% on the graph, but based off the general trend of the general model the value
% seems to be fairly accurate.

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.