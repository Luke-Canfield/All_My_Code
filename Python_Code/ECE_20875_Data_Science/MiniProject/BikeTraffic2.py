import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def main():
    degrees = [1, 2, 3, 4, 5]
    paramFits = []
    #Importing dataset
    bikeData = pd.read_csv('NYC_Bicycle_Counts_2016_Corrected.csv')
    #Feature and target matrices
    X = bikeData[['High Temp (°F)', 'Low Temp (°F)', 'Precipitation']]
    y = bikeData[['Total']]
    #Converting Matrices to Arrays
    X = X.to_numpy()
    y = y.to_numpy()
    #Converting Array to Integers and Floats and making y_column
    y_columns = len(y[0])    
    y_rows = len(y)
    y_column = []
    for i in range(y_rows):
        for j in range(y_columns):
            y[i,j] = y[i,j].replace(',', '')
            y[i,j] = int(y[i,j])
            y_column.append(y[i,j])
    
    #Making x_column for feature matrix
    x_rows = len(X)
    x_columns = len(X[0])
    for i in range(x_rows):
        for j in range(x_columns):
            X[i,j] = str(X[i,j])
            X[i,j] = X[i,j].replace('(', '')
            X[i,j] = X[i,j].replace(')', '')
            X[i,j] = X[i,j].replace('S', '')
            X[i,j] = X[i,j].replace('T', '0')
            X[i,j] = float(X[i,j])

    #Makes a single list of floats out of 3 features        
    x_column = []
    for i in range(x_rows):
            squares = (X[i,0]**2 + X[i,1]**2 + X[i,2]**2) ** 0.5
            x_column.append(squares)
      
    x_column = [float(i) for i in x_column]
    
    for i in range(0,len(degrees)):
        X = feature_matrix(x_column, degrees[i])
        paramFits.append(least_squares(X,y_column))
    print(paramFits)
    #Plots the data vs. the estimated functions
    x_model = np.linspace(min(x_column),max(x_column),500)

    for a in range(0,len(degrees)):
        y_model = [0] * len(x_model)
        for b in range(0,len(y_model)):
            for c in range(degrees[a]+1):
                y_model[b] = y_model[b] + x_model[b] ** (degrees[a] - c) * paramFits[a][c]
        plt.plot(x_model,y_model)
        
    plt.scatter(x_column,y, color="Green")
    plt.legend(["d = 1", "d = 2", "d = 3", "d = 4", "d = 5"])
    plt.title("Different Polynomial Fits")
    plt.xlabel("Weather Forecast")
    plt.ylabel("Total Bicyclists")
    plt.show()

def feature_matrix(x, d):
    
    X = [[j**(d-i) for i in range(0,d+1)] for j in x]
    return X  

def least_squares(X, y):
    X = np.array(X)
    y = np.array(y)

    B = np.linalg.inv(X.T @ X) @ (X.T @ y)
    return B

if __name__ == '__main__':
    model = main()
    