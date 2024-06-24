%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description: 
 ['This program given certain inputs by the user will calculate the '...  
'percentage of transmitted light with and without the coating that the '... 
'engineer has designed.'];
%
% Assignment Information
%   Assignment:     A05, Problem 2
%   Author:         Luke Canfield, lcanfiel@purdue.edu
%   Team ID:        13200 - 017
%   Academic Integrity:
%     [] I did not work with anyone on this assignment.
%        
%     Peers I worked with: Name, login@purdue [repeat for each]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% 
incident_A = deg2rad(45); %is the incident angle in degree
transmitted_A = deg2rad(33); %is the transmitted angle in degrees
refractive_indexC = 1.3; %is the refractive index of the coating
refractive_indexG = 1.8; % is the refractive index of the glass
refractive_indexA = 1; %is the refractive index of the air
% rCoating is the reflected intensity with coating
% rNo_Coating is the reflected intensity without coating
% T_coat is the transmitted intensity with coating
% T_noCoat is the transmitted intensity without coating
%% INITIALIZATION


%% 
rCoating = ((refractive_indexC * cos(incident_A) - refractive_indexA * ...
cos(transmitted_A)) / (refractive_indexC * cos(incident_A) + ...
refractive_indexA * cos(transmitted_A)) - (refractive_indexG * ...
cos(incident_A)- refractive_indexC * cos(transmitted_A)) / ...
(refractive_indexG * cos(incident_A) + refractive_indexC * ...
cos(transmitted_A))) ^2;
%Calculates reflected intensity with coating

T_coat = 1 - rCoating; 
%Calculates transmitted intensity with coating

rNo_Coating = ((refractive_indexG * cos(incident_A) - refractive_indexA...
* cos(transmitted_A)) / (refractive_indexG * cos(incident_A) + ...
refractive_indexA * cos(transmitted_A))) ^2;
%Calculates reflected intensity without coating

T_noCoat = 1 - rNo_Coating;
%Calculates transmitted coating without intensity
%% CALCULATIONS


%% 
fprintf('The transmitted intensity\n')
fprintf('With the coating is: %.5f\n', T_coat)
fprintf('Without the coating is: %.5f\n', T_noCoat)
%% FORMATTED TEXT & FIGURE DISPLAYS


%% 
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified. I have not provided
% access to my code to anyone in any way. The script I am 
% submitting is my own original work.





