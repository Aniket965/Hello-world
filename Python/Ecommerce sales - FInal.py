"""Mini project to predict the sales of an e-commerce website based on attributes :
1)Avg. session length'
2)Time on mobile app
3)Membership length"""

# Loading the text data into a CSV file using pandas library

import numpy
import pandas
filename = 'CustomersData.csv'

# Initialising the dataset as a csv file

data = pandas.read_csv('CustomersData.txt')

# Dropping the unwanted columns

data.drop(['Email','Address','Avatar','Time on Website'],axis=1,inplace=True)

# Extracting the features and storing it in Input

Input = data.iloc[:, 0:3]

# The matrix holding values for X0 whose all elements are 1

ones = numpy.ones( [Input.shape[0] , 1 ] )

Input = numpy.concatenate( (ones, Input), axis = 1)

# Extracting the expected output to Output variable

Output = data.iloc[:, 3:4].values

# Normalized equation used to obtain the  values of the parameters Theta

Theta = numpy.matmul(numpy.linalg.inv(numpy.matmul(Input[:450].transpose(),Input[:450])),numpy.matmul(Input[:450].transpose(),Output[:450]))

def hypothesis(X,theta):
    """The hypothesis function takes the values of the features as the input and returns a matrix of the predicted values using
    the obtained values of the parameters saved in matrix theta"""

    return numpy.matmul(X,theta)

def accuracy_checker(Input,Expected_Output):
    """The function is used to check the accuracy of the predicted output using the hypothesis function"""
    n = len(Input)
    Predicted_output = hypothesis(Input,Theta)
    check = numpy.zeros([n,1])
    for i in range(n):
        check[i] = (1 - abs(Predicted_output[i] - Expected_Output[i])/Expected_Output[i])*100
    return check.mean()

print(accuracy_checker(Input[450:],Output[450:]))

