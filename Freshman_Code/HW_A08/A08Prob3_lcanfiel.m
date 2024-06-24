%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
% This program given testing values as variables will calculate the tank
% radius, and cylindrical section length, the maximum tank volume, the
% values for fluid heights of the maximum tolerance, and the maximum
% allowable tolerance. Then it will run a loop determining if the fluid
% volume in the tank is less than the difference between the safe tank
% volume and the maxium allowable tolerance.
%
% Assignment Information
%   Assignment:     A08, Problem #3
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        Team 29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Name, login@purdue [repeat for each]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% ____________________
%% INITIALIZATION
% fluid_v = fluid volume
% height = fluid height 
% max_fluid_v = maximum tank volume
% V_tol = maximum allowable tolerance
% cylinder_l = cylindrical section length 
% R = radius of tank
% safety_v = safety volume of tank
% vector_v = list of fluid volume values in 'for' loop
% vector_h = list of height values in 'for'loop
tank_d = 4.1; %tank diameter
total_l = 20.5; %total length of tank
change_h = 0.25; %fluid height increment
safety_p = 0.8; %safety percent of tank
iterations = 0; %number of iterations

%% ____________________
%% CALCULATIONS %((pi * tank_d^2 * (3 * R - tank_d)) / 3)+
R = tank_d / 2; %calculates the radius of the tank
cylinder_l = total_l - tank_d; %calculates the cylindrical section length
max_fluid_v = ((pi * tank_d^2 * (3 * R - tank_d)) / 3) + cylinder_l *...
    (R^2 * acos((R - tank_d) / R) - (R - tank_d) * sqrt(2 * R * tank_d -...
    tank_d^2));
%calculates maximum volume of tank
V_tol = 2 * (R + 0.5 * change_h) - 0 * (R - 0.5 * change_h); 
%calculates the maximum allowable tolerance
height = 0;
safety_v = max_fluid_v * safety_p; %calculates safety volume
fluid_v = ((pi * height^2 * (3 * R - height)) / 3) + cylinder_l *...
    (R^2 * acos((R - height) / R) - (R - height) * sqrt(2 * R * height -...
    height^2));

for index = 1:9
    while fluid_v < safety_v - V_tol
        height = height + change_h * index;
        fluid_v = ((pi * height^2 * (3 * R - height)) / 3) + cylinder_l *...
        (R^2 * acos((R - height) / R) - (R - height) * sqrt(2 * R * height...
        - height^2));
    iterations = iterations + 1;
    end
end
vector_h = [0.25, 0.50, 0.75, 1, 1.25, 1.50, 1.75, 2.00, 2.25, 2.50, ...
    2.75, 3.00]; 
vector_v = [5.82, 16.55, 30.31, 46.27, 63.88, 82.68, 102.27, 122.28, ...
    142.36, 162.16, 181.32, 199.46];
%% ____________________
%% FORMATTED TEXT & FIGURE DISPLAY
fprintf("Iterations: %0.2f\n", iterations);
fprintf("Safety Volume: %0.2f\n", safety_v);
fprintf("Final fluid volume: %0.2f\n", fluid_v);

plot(vector_h,vector_v, 'ro')
title("Fluid Volume vs Fluid Height")
xlabel("Fluid Height (m)")
ylabel("Fluid Volume (m)")
grid on
axis([0, 4, 0, 205])
%% ____________________
%% RESULTS

%Iterations: 12.00
%Safety Volume: 202.09
%Final fluid volume: 199.46

%% Luke Canfield
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.







