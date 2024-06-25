
import treeplot
import numpy as np

def loadDataSet(filepath):
    '''
    Returns
    -----------------
    data: 2-D list
        each row is the feature and label of one instance
    featNames: 1-D list
        feature names
    '''
    data=[]
    featNames = None
    fr = open(filepath)
    for (i,line) in enumerate(fr.readlines()):
        array=line.strip().split(',')
        if i == 0:
            featNames = array[:-1]
        else:
            data.append(array)
    return data, featNames


def splitData(dataSet, axis, value):
    '''
    Split the dataset based on the given axis and feature value

    Parameters
    -----------------
    dataSet: 2-D list
        [n_sampels, m_features + 1]
        the last column is class label
    axis: int 
        index of which feature to split on
    value: string
        the feature value to split on

    Returns
    ------------------
    subset: 2-D list 
        the subset of data by selecting the instances that have the given feature value
        and removing the given feature columns
    '''
    subset = []
    for instance in dataSet:
        if instance[axis] == value:    # if contains the given feature value
            reducedVec = instance[:axis] + instance[axis+1:] # remove the given axis
            subset.append(reducedVec)
    return subset


def gini(labels):
    _, count = np.unique(labels, return_counts=True)
    probs = count / len(labels)
    gini_idx = 1 - np.sum(probs ** 2)
    return gini_idx

def chooseBestFeature(dataSet):
    '''
    choose best feature to split based on Gini index
    
    Parameters
    -----------------
    dataSet: 2-D list
        [n_sampels, m_features + 1]
        the last column is class label

    Returns
    ------------------
    bestFeatId: int
        index of the best feature
    '''
    best_gain = 0
    bestFeatId = -1
    num_features = len(dataSet[0]) - 1   
    total_samples = len(dataSet)

    for ID in range(num_features):
        gini_idx = gini([x[-1] for x in dataSet])  
        unique_vals = set([x[ID] for x in dataSet])

        for val in unique_vals:
            #subset = [x for x in dataSet if x[ID] == val]
            subset = splitData(dataSet, ID, val)
            gini_idx_subset = gini([x[-1] for x in subset])  

            gain = gini_idx - (len(subset) / total_samples) * gini_idx_subset

            if gain > best_gain:
                best_gain = gain
                bestFeatId = ID

    return bestFeatId  


def stopCriteria(dataSet):
    '''
    Criteria to stop splitting: 
    1) if all the classe labels are the same, then return the class label;
    2) if there are no more features to split, then return the majority label of the subset.

    Parameters
    -----------------
    dataSet: 2-D list
        [n_sampels, m_features + 1]
        the last column is class label

    Returns
    ------------------
    assignedLabel: string
        if satisfying stop criteria, assignedLabel is the assigned class label;
        else, assignedLabel is None 
    '''
    assignedLabel = None
    labels = [x[-1] for x in dataSet]
    unique_labels = np.unique(labels)

    if len(unique_labels) == 1:
        assignedLabel = unique_labels[0]
    elif len(dataSet[0]) == 1:
        assignedLabel = max(set(labels), key=labels.count)

    return assignedLabel



def buildTree(dataSet, featNames):
    '''
    Build the decision tree

    Parameters
    -----------------
    dataSet: 2-D list
        [n'_sampels, m'_features + 1]
        the last column is class label

    Returns
    ------------------
        myTree: nested dictionary
    '''
    assignedLabel = stopCriteria(dataSet)
    if assignedLabel:
        return assignedLabel

    bestFeatId = chooseBestFeature(dataSet)
    bestFeatName = featNames[bestFeatId]

    myTree = {bestFeatName:{}}
    subFeatName = featNames[:]
    del(subFeatName[bestFeatId])
    featValues = [d[bestFeatId] for d in dataSet]
    uniqueVals = list(set(featValues))
    for value in uniqueVals:
        myTree[bestFeatName][value] = buildTree(splitData(dataSet, bestFeatId, value), subFeatName)
    
    return myTree



if __name__ == "__main__":
    data, featNames = loadDataSet('car.csv')
    dtTree = buildTree(data, featNames)
    # print (dtTree) 
    treeplot.createPlot(dtTree)
    