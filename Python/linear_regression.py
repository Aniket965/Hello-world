import pandas as pa
import numpy as np
import matplotlib.pyplot as plt  

datset=pa.read_csv("Salary_Data.csv")
x= datset.ix[:,:-1].values        #indepedent experience
y= datset.ix[:,1].values        #dependent salary

from sklearn.cross_validation import train_test_split

xtrain, xtest, ytrain, ytest = train_test_split(x,y,test_size=1/3, random_state=0)

from sklearn.linear_model import LinearRegression
regressor=LinearRegression()
regressor.fit(xtrain,ytrain)

predy=regressor.predict(xtest)
tot=0
for i in range(0,len(ytest)):
    dev= abs(ytest[i]-predy[i])
    tot+=dev
average_deviation= tot/len(ytest)

#%% visuakisation of the data

plt.scatter(xtrain,ytrain,color="red")
plt.plot(xtrain,regressor.predict(xtrain),color="blue")
plt.title("salary vs experience (training set)")
plt.xlabel("experience")
plt.ylabel("salary")
plt.show()

plt.scatter(xtest,ytest,color="red")
plt.plot(xtrain,regressor.predict(xtrain),color="green")
plt.title("salary predicted vs experience (training set)")
plt.xlabel("experience")
plt.ylabel("salary")
plt.show()

