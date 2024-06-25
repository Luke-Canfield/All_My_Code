%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
% Template for A14 - Problem 2
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ____________________
%% INITIALIZATION
data_1 = readmatrix('Data_A14Prob1.csv');
x_1 = data_1(:,1);
y_1 = data_1(:,2);
x_2 = data_1(:,3);
y_2 = data_1(:,4);

%% ____________________
%% Data Linearization Calculations
x1 = log10(x_1);
y1 = log10(y_1);
x2 = log10(x_2);
y2 = log10(y_2);

coeffs_1 = polyfit(x_1, y1,1);
coeffs_2 = polyfit(x2, y2,1);

M_1 = coeffs_1(1);
B_1 = coeffs_1(2);
M_2 = coeffs_2(1); 
B_2 = coeffs_2(2);

%% ____________________
%% Text Display
fprintf("Data Set 1\n")
fprintf("Function Type: Exponential\n")
fprintf("Linearized model = %0.2f(x_1data)+%0.2f\n",M_1,B_1)

fprintf("Data Set 2\n")
fprintf("Function Type: Power\n")
fprintf("Linearized model = %0.2f(x2data)%0.2f\n",M_2,B_2)
%% ____________________
%% Figure Display
plot(x1, y1, "rd")
hold on
model_1 = M_1 * x_1 + B_1;
plot(x1, model_1, "g-")
title('Linearized Data Set 1')
xlabel("x data")
ylabel("Log10 y data")
legend("linearized data", "modeled equation","location", "best")
grid on 
hold off

figure(2)
plot(x2, y2, "bd")
hold on
model_2 = M_2 * x2 + B_2;
plot(x2, model_2, "r-")
title('Linearized Data Set 2')
xlabel("Log10 x data")
ylabel("Log10 y data")
legend("linearized data", "modeled equation","location", "best")
grid on 
hold off

%% ____________________
%% RESULTS
% A14Prob2_template
% Data Set 1
% Function Type: Exponential
% Linearized model = 0.01x+2.18
% Data Set 2
% Function Type: Power
% Linearized model = 2.26x-1.28

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.







