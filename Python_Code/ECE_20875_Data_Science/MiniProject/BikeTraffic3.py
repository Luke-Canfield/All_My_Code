import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def main():
    paramFits = []
    degrees = [1, 2, 3, 4, 5]
    #Importing dataset
    bikeData = pd.read_csv('NYC_Bicycle_Counts_2016_Corrected.csv')
    #Feature and target matrices
    X = bikeData[['Total']]
    y = bikeData[['Precipitation']]
    #Converting Matrices to Arrays
    X = X.to_numpy()
    y = y.to_numpy()
    #Converting Array to Integers
    columns = len(y[0])    
    rows = len(y)
    for i in range(rows):
        for j in range(columns):
            X[i,j] = X[i,j].replace(',', '')
            X[i,j] = int(X[i,j])

    #Making x_column for feature matrix
    for i in range(rows):
        for j in range(columns):
            y[i,j] = str(y[i,j])
            y[i,j] = y[i,j].replace('(', '')
            y[i,j] = y[i,j].replace(')', '')
            y[i,j] = y[i,j].replace('S', '')
            y[i,j] = y[i,j].replace('T', '0')
            y[i,j] = float(y[i,j])
    #Converts x_column into a list of floats
    x_column = []
    for i in range(len(X)):
        x_column.append(X[i])

    x_column = [float(i) for i in x_column]    
    #Calculates feature matrix and parameters for listed degrees of freedom
    for i in range(0,len(degrees)):
        X = feature_matrix(x_column, degrees[i])
        paramFits.append(least_squares(y,X))
    print(paramFits)
    #Plots the data vs. the estimated functions
    x_model = np.linspace(min(y),max(y),500)

    for a in range(0,len(degrees)):
        y_model = [0] * len(x_model)
        for b in range(0,len(y_model)):
            for c in range(degrees[a]+1):
                y_model[b] = y_model[b] + x_model[b] ** (degrees[a] - c) * paramFits[a][c]
        plt.plot(x_model,y_model)
        
    plt.scatter(y,x_column, color="Green")
    plt.legend(["d = 1", "d = 2", "d = 3", "d = 4", "d = 5"])
    plt.title("Different Polynomial Fits")
    plt.xlabel("Precipitation Level")
    plt.ylabel("Total Bicyclists")
    plt.show()
    
#Function that builds feature matrix
def feature_matrix(x, d):
    
    X = [[a**(d-i) for i in range(0,d+1)] for a in x]
    return X

#Function that calculates least-squares solution
def least_squares(y, X):
    X = np.array(X)
    y = np.array(y)

    B = np.linalg.inv(X.T @ X) @ (X.T @ y)
    B = [float(i) for i in B]
    return B

if __name__ == '__main__':
    model = main()
    
    
