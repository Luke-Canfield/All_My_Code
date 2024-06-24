%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program analayzes a set of data and will display the correct
% linearized graph. It will also calculate the linearized model for the
% data.
%
% Assignment Information
%   Assignment:     A14, Problem 4
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
data_1 = readmatrix('Data_problem4.csv');
x_1 = data_1(:,1);
y_1 = data_1(:,2);

x1 = log10(x_1);
y1 = log10(y_1);

%% ____________________
%% PLOTS WITH AXIS SCALING
subplot(2,2,1)
plot(x_1,y_1,'bs')
title("Linear vs. Linear")
xlabel("x-data-1")
ylabel("y-data-1")
grid on 
hold on

subplot(2,2,2)
semilogx(x_1,y_1,'ro')
title("Logx vs. Linear")
xlabel("log10x-data-1")
ylabel("y-data-1")

subplot(2,2,3)
semilogy(x_1,y_1,'gs')
title("Linear vs. Log y")
xlabel("x-data-1")
ylabel("log10 y-data-1")

subplot(2,2,4)
loglog(x_1,y_1,'ys')
title("Log x vs. Log y")
xlabel("log10x-data-1")
ylabel("log10y-data-1")
grid off 
hold off

%% ____________________
%% LINEARIZED MODEL

%%% DATA LINEARIZATION & MODEL
coeffs_1 = polyfit(x1, y1,1);
M_1 = coeffs_1(1); 
B_1 = coeffs_1(2);

%%% TEXT DISPLAY
fprintf("Linearized model = %0.2f*(x_1data)+%0.2f\n",M_1,B_1)

%%% FIGURE DISPLAY
figure(2)
plot(x1, y1, "bd")
hold on
model_1 = M_1 * x1 + B_1;
plot(x1, model_1, "r-")
title('Linearized Data Set 2')
xlabel("Log10 x data")
ylabel("Log10 y data")
legend("linearized data", "linear model","location", "best")
grid on 
hold off

%% ____________________
%% DETERMINE MODEL

%%% PARAMETER IDENTIFICATION
m_model_1 = M_1;
b_model_1 = 10^(B_1);

%%% TEXT DISPLAY
fprintf("General Model = %0.2f*(x_1data).^%0.2f\n",b_model_1,m_model_1)
fprintf("Function Type: Power\n")

%%% FIGURE DISPLAY
figure(3)
plot(x_1, y_1, "bs")
hold on
model_2 = b_model_1 * x_1.^ (m_model_1);
plot(x_1, model_2, "g-")
title('Original Data vs. General Model')
xlabel("x data")
ylabel("y data")
legend("original data", "general model","location", "best")
grid on 
hold off


%% ____________________
%% ANALYSIS
% A14Prob4_template
% Linearized model = 7.37*(x_1data)+0.71
% General Model = 5.08*(x_1data).^7.37
% Function Type: Power

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.