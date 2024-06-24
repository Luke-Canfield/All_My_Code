%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Script for A05 Problem 3: MATLAB Skills - Plots
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% INITIALIZATION
x = [38.12, 38.92, 44.54, 46.61, 50.18, 50.53, 56.08, 60.77, 63.83,...
64.63, 68.76, 70.12];
y1 = [48.03, 51.8, 64.08, 69.1, 81.85, 88.62, 95.26, 107.53, 124.31,...
    129.98, 137.93, 151.45];
y2 = [42.91, 47.79, 53.46, 61.88, 71.88, 81.75, 93.66, 102.64, 110.98,...
    124.32, 126.91, 149.57];
%% ____________________
%% FIGURE 1
plot(y1,x, 'ro')
title("Y1 vs X")
xlabel('X')
ylabel('Y1')
grid on
% Plots the y1 data versus the x data
%% ____________________
%% FIGURE 2
subplot(2,2,1)
plot(y1,x, 'ro')
title("Y1 vs X")
xlabel('X')
ylabel('Y1')
grid on
axis([30 160 20 80])
% Plots y1 data versus the x data in the top subplot

subplot(2,2,3)
plot(y2,x, 'bd')
title("Y2 vs X")
xlabel('X')
ylabel('Y2')
grid on
axis([30 160 20 80])
% Plots y2 data versus the x data in the bottom subplot
%% ____________________
%% FIGURE 3
plot(y1,x, 'ro')
title("Y vs X")
xlabel('X')
ylabel('Y')
grid on

hold on
% Plots the y1 data versus the x data

plot(y2,x, 'bd')
legend('Y1 vs X', 'Y2 vs X',"Location",'best')
hold off 
%Plots the y1 and y2 data versus the x data on the same graph
%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.





