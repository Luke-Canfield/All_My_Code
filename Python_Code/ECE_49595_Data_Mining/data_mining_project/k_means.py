import pandas as pd
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# Load the data from the CSV file
data = pd.read_csv('WACO.csv')

# Select the attributes for clustering
attributes = ['Score', 'Fairway Hits', 'C1 Reg', 'C2 Reg', 'C1 Putting', 'C2 Putting', 'OB']
X = data[attributes]

# Perform K-means clustering
kmeans = KMeans(n_clusters= 3, random_state = 42)  # You can adjust the number of clusters as needed
kmeans.fit(X)
clusters = kmeans.predict(X)

# Add cluster labels to the dataframe
data['Cluster'] = clusters

# Display cluster centers
cluster_means = pd.DataFrame(kmeans.cluster_centers_, columns=attributes)

# Print cluster means for each attribute
print("Cluster Means for Each Attribute:")
print(cluster_means)
#print("Cluster Centers:")
#print(kmeans.cluster_centers_)

# Visualize the clusters
scatter = plt.scatter(X['Score'], X['C1 Reg'], c=clusters, cmap='viridis')
plt.xlabel('Score Under Par')
plt.ylabel('C1 Reg (%)')
plt.title('Prodigy Presents WACO')
handles, labels = scatter.legend_elements()
plt.legend(handles, labels, title='Cluster')

for i, txt in enumerate(data['Name']):
    #if ((X['C1 Reg'][i] == 0.61) & (X['Score'][i] == 37)):
    #    plt.annotate(txt, (X['Score'][i], X['C1 Reg'][i]), xytext=(25, 5*i - 15), textcoords='offset points', ha='right', va='bottom', fontsize=8)    
    if(i % 2 == 0):  # Stagger the positions of annotations
        plt.annotate(txt, (X['Score'][i], X['C1 Reg'][i]), xytext=(40, 2), textcoords='offset points', ha='right', va='bottom', fontsize=8)
    else:
        plt.annotate(txt, (X['Score'][i], X['C1 Reg'][i]), xytext=(-10, -3), textcoords='offset points', ha='left', va='top', fontsize=8)

plt.show()