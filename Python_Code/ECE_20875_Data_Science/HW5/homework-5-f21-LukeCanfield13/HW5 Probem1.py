import numpy as np
from scipy.stats import norm

File0 = open('engagement_0.txt')
data_0 = File0.readlines()
File0.close()
File1 = open('engagement_1.txt')
data_1 = File1.readlines()
File1.close()

data_0 = [float(x) for x in data_0]
data_1 = [float(x) for x in data_1]

#Question 2
U = 0.75
N_1 = len(data_1)
avg_1 = np.mean(data_1)
SD_1 = np.std(data_1, ddof = 1)
SE_1 = SD_1 / (N_1 ** (1/2))
Z_score = (abs(avg_1 - U)) / SE_1
p = norm.cdf(Z_score)
P_value = 1 - p
print("--Question 2--")
print("Engagement_1 Sample Size:",N_1)
print("Engagement_1 Sample Mean:",avg_1)
print("Standard Error:",SE_1)
print("Standard Score:", Z_score)
print("P-value:",P_value)

#Question 3
    #looked at z-table to find z-score 
z_score = 1.65
SE = (abs(avg_1 - U)) / z_score
N = (SD_1 / SE)**2

print("--Question 3--")
print("Largest Standard Error:",SE)
print("Minimum Sample Size:",N)

#Question 5
N_0 = len(data_0)
avg_0 = np.mean(data_0)
SD_0 = np.std(data_0, ddof = 1)
SE_0 = SD_0 / (N_0 ** (1/2))
SE_avg = (SE_0 + SE_1) / 2
zScore = (abs(avg_1 - avg_0)) / SE_avg
p0 = norm.cdf(zScore)
p_value = 1 - p0

print("Question 5--")
print("Engagement_0 Sample Size:",N_0)
print("Engagement_0 Sample Mean:",avg_0)
print("Engagement_1 Sample Size:",N_1)
print("Engagement_1 Sample Mean:",avg_1)
print("Standard Error:",SE_avg)
print("Z-Score:", zScore)
print("P-value:",p_value)

