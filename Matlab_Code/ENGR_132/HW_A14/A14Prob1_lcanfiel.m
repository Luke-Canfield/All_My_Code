%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
% Template for A14 - Problem 1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% ____________________
%% INITIALIZATION
data_1 = readmatrix('Data_A14Prob1.csv');
x_1 = data_1(:,1);
y_1 = data_1(:,2);
x_2 = data_1(:,3);
y_2 = data_1(:,4);

x1 = log10(x_1);
y1 = log10(y_1);
x2 = log10(x_2);
y2 = log10(y_2);

%% ____________________
%% FORMATTED FIGURES

% Formatted Figure 1 - DATA SET 1
subplot(2,2,1)
plot(x_1,y_1,'bs')
title("Original Data")
xlabel("xdata-1")
ylabel("ydata-1")
grid on 
hold on

subplot(2,2,2)
semilogx(x_1,y_1,'ro')
title("Log x vs. y data")
xlabel("xdata-1")
ylabel("ydata-1")
grid on

subplot(2,2,3)
semilogy(x_1,y_1,'gs')
title("x data vs. Log y")
xlabel("xdata-1")
ylabel("ydata-1")
grid on

subplot(2,2,4)
loglog(x_1,y_1,'ys')
title("Log x vs. Log y")
xlabel("xdata-1")
ylabel("ydata-1")
grid on 
hold off
% Formatted Figure 2 - DATA SET 2
figure(2)
subplot(2,2,1)
plot(x_2,y_2,'bs')
title("Original Data")
xlabel("xdata-2")
ylabel("ydata-2")
grid on 
hold on

subplot(2,2,2)
semilogx(x_2,y_2,'ro')
title("Log x vs. y data")
xlabel("xdata-2")
ylabel("ydata-2")

subplot(2,2,3)
semilogy(x_2,y_2,'gs')
title("x data vs. Log y")
xlabel("x-data-2")
ylabel("ydata-2")

subplot(2,2,4)
loglog(x_2,y_2,'ys')
title("Log x vs. Log y")
xlabel("xdata-2")
ylabel("ydata-2")
grid off 
hold off

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.







