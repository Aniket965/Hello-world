import pandas as pa
import numpy as np
import matplotlib.pyplot as plt  

datset=pa.read_csv("Position_Salaries.csv")
x= datset.ix[:,1:2].values
y= datset.ix[:,-1].values

from sklearn.linear_model import LinearRegression

#linear regression
reg1=LinearRegression()
reg1.fit(x,y)

#poly linear regression
from sklearn.preprocessing import PolynomialFeatures
c=PolynomialFeatures(degree=5)
xpoly=c.fit_transform(x)
reg2=LinearRegression()
reg2.fit(xpoly,y)

#visualisation of linear
plt.scatter(x,y)
plt.plot(x,reg1.predict(x),color="red")
plt.xlabel("values")
plt.ylabel("predicted linear")
plt.title("linear")
plt.show()
#visualisation of poly linear
#%%
xgrid=np.arange(min(x),max(x),0.1)
xgrid=xgrid.reshape(len(xgrid),1)
#%%
plt.scatter(x,y,color="red")
plt.plot(xgrid,reg2.predict(c.fit_transform(xgrid)),color="orange")
plt.xlabel("values")
plt.ylabel("predicted linear")
plt.title("linear")
plt.show()

#%% final prediction using linear model
reg1.predict(6.5)
#%% final prediction using poly linear model
reg1.predict(c.fit_transform(6.5))