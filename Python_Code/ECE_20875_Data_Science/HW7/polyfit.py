import numpy as np
import matplotlib.pyplot as plt

#Return fitted model parameters to the dataset at datapath for each choice in degrees.
#Input: datapath as a string specifying a .txt file, degrees as a list of positive integers.
#Output: paramFits, a list with the same length as degrees, where paramFits[i] is the list of
#coefficients when fitting a polynomial of d = degrees[i].
def main(datapath, degrees):
    paramFits = []
    
    f = open(datapath)
    file = f.read()
    x_column = []
    y_column = []
    x1 = file.split()
    for i in range(0,len(x1)):
        if i % 2 == 0:
            x_column.append(x1[i])
        else:
            y_column.append(x1[i])

    x_column = [float(i) for i in x_column]
    y_column = [float(i) for i in y_column]
    


    for i in range(0,len(degrees)):
        X = feature_matrix(x_column, degrees[i])
        paramFits.append(least_squares(X,y_column))
    
    x_model = np.linspace(min(x_column),max(x_column),500)

    for a in range(0,len(degrees)):
        y_model = [0] * len(x_model)
        for b in range(0,len(y_model)):
            for c in range(degrees[a]+1):
                y_model[b] = y_model[b] + x_model[b] ** (degrees[a] - c) * paramFits[a][c]
        plt.plot(x_model,y_model)
        
    plt.scatter(x_column,y_column, color="Green")
    plt.legend(["d = 1", "d = 2", "d = 3", "d = 4", "d = 5"])
    plt.title("Different Polynomial Fits")
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.show()
    print("Parameter Fits:", paramFits)
    return paramFits

def feature_matrix(x, d):
    
    X = [[a**(d-i) for i in range(0,d+1)] for a in x]
    print("Feature Matrix:",X)
    return X

def least_squares(X, y):
    X = np.array(X)
    y = np.array(y)

    B = np.linalg.inv(X.T @ X) @ (X.T @ y)
    print("Least Squares:",B)
    return B

if __name__ == '__main__':
    datapath = 'poly.txt'
    degrees = [1, 2, 3, 4, 5]

    paramFits = main(datapath, degrees)
    print(paramFits[1],paramFits[3])
