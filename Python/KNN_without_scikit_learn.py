
# coding: utf-8

# In[64]:


#importing libraries
#!pip install pandas
#!pip install matplotlib
#!pip install sklearn

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


# In[71]:


#loading dataset
dataset = pd.read_csv("diabetes.csv")
dataset.head(5)#to visialize dataset


# In[72]:


''' 
 About data set
 Here we need to predict the class label as outcome whether the person has diabetes or not
 given Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin, BMI, DiabetesPedigreeFunction, Age. we need to find whether the person has diabetes or not
'''


# In[73]:


# lets find how many classes are there in Species
dataset["Outcome"].value_counts()


# In[74]:


# we can see that the classes are balanced with 50 each so knn works well without any biased


# In[75]:


#splitting the dataset into Train, Dev, Test
# Train dataset which we use to train the model(KNN)
# Dev dataset which we use to find the best K value
# Test dataset which we test the model with the K value we got from above step

# Why we are using 3 datasets? Because we need to reduce generalization error(G). THis is the error which we got from new data(Test data).Because we are finding the best K value using Dev dataset.
label_data = dataset["Outcome"]
del dataset["Outcome"]
eighty_percent_data = (80*dataset.shape[0])//100
X_train, X_test, y_train, y_test = dataset[:eighty_percent_data],dataset[eighty_percent_data:],label_data[:eighty_percent_data],label_data[eighty_percent_data:]
eighty_percent_data = (80*len(X_train))//100
X_train, X_dev, y_train, y_dev = X_train[:eighty_percent_data],X_train[eighty_percent_data:],y_train[:eighty_percent_data],y_train[eighty_percent_data:]


# In[79]:


# first we find distances of each point in dev set with train set
# np.linalg.norm will find the distance between two points
distances = []
for i in range(len(X_dev)):
    each_distance = []
    for j in range(len(X_train)):
        each_distance.append((np.linalg.norm(X_dev.iloc[i]-X_train.iloc[j]),j))
    distances.append(sorted(each_distance)) #sorting the distance in ascending order


# In[89]:


# Now we Train the model with the different K values
K_values = [1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31]
accuracy_scores = []
for i in K_values:
    pred = []
    for j in range(len(X_dev)):
        zero_count,one_count = 0,0 #used for majority voting
        for k in range(i):
            if y_train.iloc[distances[j][k][1]]==0:
                zero_count+=1
            else:
                one_count+=1
        if zero_count>one_count:
            pred.append(0)
        else:
            pred.append(1)
        correct_count = 0
        for l in range(len(pred)):
            if pred[l] == y_dev.iloc[l]:
                correct_count+=1
    accuracy_scores.append(correct_count/len(pred))


# In[91]:


optimal_k = K_values[accuracy_scores.index(max(accuracy_scores))]


# In[92]:


print('\nThe optimal number of neighbors is %d.' % optimal_k)
plt.plot(K_values, accuracy_scores)
plt.xlabel('Number of Neighbors K')
plt.ylabel('Accuracy score')
plt.show()


# In[95]:


#here we can see that K=15 has highest accuracy. Now we build the model with K=15 on unseen data(Test dataset)
distances = []
for i in range(len(X_test)):
    each_distance = []
    for j in range(len(X_train)):
        each_distance.append((np.linalg.norm(X_test.iloc[i]-X_train.iloc[j]),j))
    distances.append(sorted(each_distance)) #sorting the distance in ascending order


# In[102]:


#predicting the data with 15 neigbhors
pred = []
for j in range(len(X_test)):
    zero_count,one_count = 0,0 #used for majority voting
    for k in range(i):
        if y_train.iloc[distances[j][k][1]]==0:
            zero_count+=1
        else:
            one_count+=1
    if zero_count>one_count:
        pred.append(0)
    else:
        pred.append(1)
    correct_count = 0
    for l in range(len(pred)):
        if pred[l] == y_test.iloc[l]:
            correct_count+=1
print("accuracy score ",(correct_count/len(pred))*100)

