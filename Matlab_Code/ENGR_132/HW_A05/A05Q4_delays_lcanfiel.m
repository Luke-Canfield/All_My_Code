%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program plots two sets of delay data against each other to compare
% which type of delay is limiting the speed of the processing of the system
% on a chip.
%
% Assignment Information
%   Assignment:     A05, Problem 4
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        13200-017
%   Academic Integrity:
%     [] I worked with no one on this assignment.
%        
%     Peers I worked with: N/A
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 
%% INITIALIZATION
Delay_Data = readmatrix('Delay_Data.csv'); %variable for 3x3 matrix of data
Time_G = Delay_Data(:,1); %variable for the generation of each delay
G_delay = Delay_Data(:,2); %variable for gate delay
I_delay = Delay_Data(:,3); %variable for interconnect delay
X_vector = [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,...
1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,...
3.4,3.5,3.6,3.7,3.8,3.9,4.0,4.1,4.2,4.3,4.4,4.5,4.6,4.7,4.8,4.9,5.0,5.1,...
5.2,5.3,5.4,5.5,5.6,5.7,5.8,5.9,6.0,6.1,6.2,6.3,6.4,6.5,6.6,6.7,6.8,6.9,...
7.0]; %variable used to calculate model lines
C1 = 0.36; %constant used in equation that models interconnect delay
C2 = 25.41; %constant used in equation that models gate delay

% Minimum_t = the minimum value of the total delay
% Eq_I = C1 * exp(0.47(x)) equation that models the interconnect delay
% Eq_G = C2 * exp(-0.34(x)) equation that models the gate delay
% T_delay is the sum of the gate and interconnect delays for each generation
%% ____________________
%% CALCULATIONS
T_delay = G_delay + I_delay; %calculates the total delay 

Eq_I = C1 * exp(0.47 * ([X_vector])); 
%calculates model line for interconnect 

Eq_G = C2 * exp(-0.34 * ([X_vector])); %calculates model line for gate

Minimum_t = min(T_delay);
%% ____________________
%% FIGURE DISPLAY
plot(Time_G,G_delay, 'bd')
title('Gate and Interconnect Delay vs Generation')
xlabel('Generation Number')
ylabel('Delay in picoseconds (ps)')
grid on 

hold on 
%Plots the Gate Delay data versus the generation number

plot(Time_G,I_delay, 'ro')
%Plots the Interconnect Delay data versus the generation number

plot(Time_G,T_delay, 'gs')
%Plots the Total Delay for each generation

plot(Eq_I,'--')
%Plots the model line for the interconnect delay

plot(Eq_G,'-')
legend('G_delay vs Time_G','I_delay vs Time_G','T_delay vs Time_G',...
    'Eq_I = dashed line','Eq_G = solid line',"location",'best')
axis([0 40 0 20])
hold off
%% ____________________
%% TEXT DISPLAY
fprintf('The minimum value of the total delay is: %.3f\n',Minimum_t)


%% ____________________
%% RESULTS
%The minimum value of the total delay is: 8.492


%% ____________________
%% ANALYSIS

% -- 1.
% Generation seven has the minimum gate delay. Generation one has the
% minimum interconnect delay. On the graph the gate delay is a decreasing
% function which is why the last generation (seven) has the minimum. The
% interconnect delay is an increasing function so its first generation
% (ones) has its minimum.

% -- 2.
% Generation five has the minimum total delay. This generation is different
% that either of the other displays because this is where the gate delay 
% and interconnect delay functions almost intersect making it the lowest
% total delay generation.

% -- 3. 
% An example of where the original raw data would be helpful in a situation
%where a company is trying to sell to investers and their data over the 
%last couple of years shows that they continue to increase the efficiency 
%of their product making the investers more likely to invest into their 
%product. An example where the model would be most helpful is if a company 
%was trying to predict what their numbers such as cost or revenue were 
%going to look like in the near future.
%near future



%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.