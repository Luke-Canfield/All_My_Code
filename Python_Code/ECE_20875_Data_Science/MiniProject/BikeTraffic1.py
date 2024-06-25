import pandas as pd

def main():
    #Importing dataset
    bikeData = pd.read_csv('NYC_Bicycle_Counts_2016_Corrected.csv')
    #Feature and target matrices
    X = bikeData[['Date', 'Day', 'High Temp (°F)', 'Low Temp (°F)', 'Precipitation']]
    y = bikeData[['Brooklyn Bridge', 'Manhattan Bridge', 'Williamsburg Bridge', 'Queensboro Bridge','Total']]
    #Converting Matrices to Arrays
    X = X.to_numpy()
    y = y.to_numpy()
    #Converting Array to Integers
    columns = len(y[0])    
    rows = len(y)
    length = rows
    for i in range(rows):
        for j in range(columns):
            y[i,j] = y[i,j].replace(',', '')
            y[i,j] = int(y[i,j])
    #List of average bicyclists for each bridge        
    ListavgB = []
    ListavgM = []
    ListavgW = []
    ListavgQ = []
    for i in range(rows):
        for j in range(columns-1):
            total = y[i,4]
            if j == 0:
                ListavgB.append(y[i,j] / total)
            elif j == 1:
                ListavgM.append(y[i,j] / total)
            elif j == 2:
                ListavgW.append(y[i,j] / total)
            elif j == 3:
                ListavgQ.append(y[i,j] / total)     
    manAvg = 0
    willAvg = 0
    queenAvg = 0
    brookAvg = 0
    #Totaling Averages of bicyclists on each bridge
    for i in range(len(y)):
        brookAvg += ListavgB[i]
        manAvg += ListavgM[i]
        willAvg += ListavgW[i]
        queenAvg += ListavgQ[i]

    print("The average percentage of bicyclists on any given day on Brooklyn Bridge: ",(brookAvg / length) * 100)
    print("The average percentage of bicyclists on any given day on Manhattan Bridge: ",(manAvg / length) * 100)
    print("The average percentage of bicyclists on any given day on Queensboro Bridge: ",(queenAvg / length) * 100)
    print("The average percentage of bicyclists on any given day on Williamsburg Bridge: ",(willAvg / length) * 100)   

if __name__ == '__main__':
    model = main()
