import pandas as pa
import numpy as np
import matplotlib.pyplot as plt  

datset=pa.read_csv("Position_Salaries.csv")
x= datset.ix[:,1:2].values
y= datset.ix[:,-1].values

#%%
from sklearn.ensemble import RandomForestRegressor
regressor=RandomForestRegressor(n_estimators=500,random_state=0)
regressor.fit(x,y)
#%%
ypred=regressor.predict(6.5)

#%%
xgrid=np.arange(min(x),max(x),0.01)
xgrid=xgrid.reshape(len(xgrid),1)

plt.scatter(x,y,color="red")
plt.plot(xgrid,regressor.predict((xgrid)),color="orange")
plt.xlabel("values")
plt.ylabel("predicted linear")
plt.title("linear")
plt.show()