import numpy as np
from scipy.stats import norm
from scipy.stats import t

#Question 1
prob1 = 0.90
data = [-23, -16, -3, -9, -1, 13, -16, 15, 31, -22, -14, -25]
N = len(data)
avg = np.mean(data)
Sd = np.std(data, ddof = 1)
SE = Sd / (N**(1/2))
t_stat = t.ppf(prob1, N - 1)
X = N**0.5
i1 = avg + t_stat*(Sd / X)
i2 = avg - t_stat*(Sd / X)

print("--Question 1--")
print("Sample Mean:",avg)
print("Standard Error",SE)
print("Standard Statistic:",t_stat)
print("Interval:",[i1,i2])

#Question 2
prob2 = 0.95
T_stat = t.ppf(prob2, N - 1)
I1 = avg + T_stat*(Sd / X)
I2 = avg - T_stat*(Sd / X)

print("--Question 2--")
print("Standard Statistic:",T_stat)
print("Interval:",[I1,I2])

#Question 3
std = 16.836
sError = std / N**0.5
zScore = norm.ppf(prob2)
x1 = avg + zScore*(Sd / X)
x2 = avg - zScore*(Sd / X)

print("--Question 3--")
print("Standard Error:",sError)
print("Z-score:",zScore)
print("Interval:",[x1,x2])

#Questiom 5
cInterval = t.cdf(1.15217, N - 1)

print("--Question 5--")
print("Confidence Level:",cInterval)