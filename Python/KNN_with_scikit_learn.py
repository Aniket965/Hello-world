
# coding: utf-8

# In[21]:


#importing libraries
#!pip install pandas
#!pip install matplotlib
#!pip install sklearn

import pandas as pd
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score


# In[46]:


#loading dataset
dataset = pd.read_csv("diabetes.csv")
dataset.head(5)#to visialize dataset


# In[47]:


''' 
 About data set
 Here we need to predict the class label as outcome whether the person has diabetes or not
 given Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin, BMI, DiabetesPedigreeFunction, Age. we need to find whether the person has diabetes or not
'''


# In[48]:


# lets find how many classes are there in Species
dataset["Outcome"].value_counts()


# In[49]:


# we can see that the classes are balanced with 50 each so knn works well without any biased


# In[50]:


#splitting the dataset into Train, Dev, Test
# Train dataset which we use to train the model(KNN)
# Dev dataset which we use to find the best K value
# Test dataset which we test the model with the K value we got from above step

# Why we are using 3 datasets? Because we need to reduce generalization error(G). THis is the error which we got from new data(Test data).Because we are finding the best K value using Dev dataset.
label_data = dataset["Outcome"]
del dataset["Outcome"]
X_train, X_test, y_train, y_test = train_test_split(dataset, label_data, test_size=0.2)
#test_size = size of the test set 0.2 = 20% data .learn more at http://scikit-learn.org/stable/modules/generated/sklearn.model_selection.train_test_split.html
X_train, X_dev, y_train, y_dev = train_test_split(X_train, y_train, test_size=0.2)


# In[57]:


# Now we Train the model with the different K values
K_values = [1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31]
accuracy_scores = []
for i in K_values:
    clf = KNeighborsClassifier(n_neighbors = i)
    clf.fit(X_train,y_train)
    pred = clf.predict(X_dev)
    accuracy_scores.append(accuracy_score(y_dev,pred))


# In[58]:


optimal_k = K_values[accuracy_scores.index(max(accuracy_scores))]


# In[60]:


print('\nThe optimal number of neighbors is %d.' % optimal_k)
plt.plot(K_values, accuracy_scores)
plt.xlabel('Number of Neighbors K')
plt.ylabel('Accuracy score')
plt.show()


# In[62]:


#here we can see that K=7 has highest accuracy. Now we build the model with K=7 on unseen data(Test dataset)
clf = KNeighborsClassifier(n_neighbors = 7)
clf.fit(X_train,y_train)
pred = clf.predict(X_test)
print("accuracy score ",accuracy_score(y_test,pred))


# In[63]:


#we can see that KNN doesn't work well. Later we try differnt algorith's on this dataset

