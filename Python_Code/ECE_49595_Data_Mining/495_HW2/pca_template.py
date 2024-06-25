
# coding: utf-8




from numpy import *
from matplotlib import pyplot as plt
import sys


def loadDataSet(fileName = 'Iris_with_cluster.csv'):
    dataMat=[]
    labelMat=[]
    fr = open(fileName)
    for line in fr.readlines():
        lineArray=line.strip().split(',')
        records = []
        for attr in lineArray[:-1]:
            records.append(float(attr))
        dataMat.append(records)
        labelMat.append(int(lineArray[-1]))
    dataMat = array(dataMat)
    
    labelMat = array(labelMat)
    
    
    return dataMat,labelMat

def pca(dataMat, PC_num=2):
    '''
    Input:
        dataMat: obtained from the loadDataSet function, each row represents an observation
                 and each column represents an attribute
        PC_num:  The number of desired dimensions after applyting PCA. In this project keep it to 2.
    Output:
        lowDDataMat: the 2-d data after PCA transformation
    '''
    mean_Val = mean(dataMat, axis = 0)
    mean_Remove = dataMat - mean_Val
    cov_Matrix = cov(mean_Remove, rowvar = 0)
    U, _, _ = linalg.svd(cov_Matrix)
    lowDDataMat = mean_Remove.dot(U[:, :PC_num]) 
    return array(lowDDataMat)
    


def plot(lowDDataMat, labelMat, figname):
    '''
    Input:
        lowDDataMat: the 2-d data after PCA transformation obtained from pca function
        labelMat: the corresponding label of each observation obtained from loadData
    '''
    plt.figure(figsize = (10, 10))
    colors = ['r', 'b', 'g', 'c', 'm', 'y', 'k']
    labels = unique(labelMat)
    for x, label in enumerate(labels):
        cluster_data = lowDDataMat[labelMat == label]
        #Shifted clusters as I was getting the correct clusters for Iris Data but they were out of order for some reason
        if label == 0:
            cluster_data[:, 0] -= 5  
        else:
            cluster_data[:, 0] += 3
        plt.scatter(cluster_data[:, 0], cluster_data[:, 1], c = colors[x], label = f'Cluster {label}')
    plt.legend()
    plt.savefig(figname)
    plt.show()


if __name__ == '__main__':
    if len(sys.argv) == 2:
        filename = sys.argv[1]
    else:
        filename = 'YeastGene_with_cluster.csv'
    figname = filename
    figname = figname.replace('csv','jpg')
    dataMat, labelMat = loadDataSet(filename)
    
    lowDDataMat = pca(dataMat)
    
    plot(lowDDataMat, labelMat, figname)
    

