function [pool_vol] = A10_poolSubfunction_kmongkon(L1, L2, Ds, Dd)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ENGR 132 
% Program Description 
% This sub function will compute the standard pool volume.
%
% Function Call
% [pool_vol] = A10_poolSubfunction_kmongkon(L1, L2, Ds, Dd)
%
% Input Arguments
% L1 % Surface length
% L2 % Surface width
% Ds % Shallow end depth
% Dd % Deep end depth
%
% Output Arguments
% pool_vol % Standard pool volume
%
% Assignment Information
%   Assignment:     A10, Problem 1
%   Author:         Kasin, kmongon@purdue.edu
%   Team ID:        017-29
%   Academic Integrity:
%     [] I worked with one or more peers but our collaboration
%        maintained academic integrity.
%     Peers I worked with: Name, login@purdue [repeat for each]
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% ____________________
%% INITIALIZATION
%if (L1 < 0) | (L2 < 0) | (Ds < 0) | (Dd < 0)
%    disp('Enter positive value');
%else
%    Sec_1 = (((L1) / (3)) * L2 * Ds);
%    Sec_2 = ((1 /2) * (Ds + Dd) * ((L1) / (3)) * L2);
%    Sec_3 = (((1 /2) * (Ds + Dd) * ((L1) / (3))) * L2);
%    pool_vol = (Sec_1 + Sec_2 + Sec_3);
%end


%% ____________________
%% CALCULATIONS

%if (L1 < 0) | (L2 < 0) | (Ds < 0) | (Dd < 0)
%    disp('Enter positive value');
%else
%    Sec_1 = (((L1) / (3)) * L2 * Ds);
%    Sec_2 = ((1 /2) * (Ds + Dd) * ((L1) / (3)) * L2);
%    Sec_3 = (((1 /2) * (Ds + Dd) * ((L1) / (3))) * L2);
%    pool_vol = (Sec_1 + Sec_2 + Sec_3);
%end
% Calculate the section of the pool volume
Sec_1 = (((L1) / (3)) * L2 * Ds);
Sec_2 = ((1 /2) * (Ds + Dd) * ((L1) / (3)) * L2);
Sec_3 = (((1 /2) * (Ds + Dd) * ((L1) / (3))) * L2);
pool_vol = (Sec_1 + Sec_2 + Sec_3);

if (L1 >= 0) & (L2 >= 0) & (Ds >= 0) & (Dd >= 0)
    pool_vol;
else
    disp('Enter positive value');
end

end

% L1/3 = ((L1) / (3));
%Sec_1 = (((L1) / (3)) * L2 * Ds);
%Sec_2 = ((1 /2) * (Ds + Dd) * ((L1) / (3)) * L2);
%Sec_3 = (((1 /2) * (Ds + Dd) * ((L1) / (3))) * L2);
%pool_vol = (Sec_1 + Sec_2 + Sec_3);
%end

%% ____________________
%% FORMATTED TEXT/FIGURE DISPLAYS


%% ____________________
%% COMMAND WINDOW OUTPUT


%% ____________________
%% ACADEMIC INTEGRITY STATEMENT
% I have not used source code obtained from any other unauthorized
% source, either modified or unmodified.  Neither have I provided
% access to my code to another. The function I am submitting
% is my own original work.



