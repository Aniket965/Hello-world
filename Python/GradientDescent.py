'''
    Topic: Gradient Descent (Practical) using only NumPy and Python.
    Author: Yash Sharma (github.com/Yashs744)
'''

# Library
import numpy as np

# Class GradientDescent
class GradientDescent:
    def __init__(self, lr):
        '''
            Initialize 'm' and 'c' (from y = mx + c) and Learning Rate.    
            
            Arguments:
                lr {float} -- Learning Rate
        '''

        self.m = 0
        self.c = 0

        self.lr = lr

    def predict(self, x):
        ''' 
            Arguments:
                x {float | int} -- Value of independent variable to produce output.
            
            Returns:
                float -- Value of yHat i.e value of 'mx + c'
        '''

        return (x * self.m + self.c)
    
    def cost(self, x, y):
        '''
            Calculate Cost i.e error between real value of y and yHat.
            Error Function: Sum of Squares.
            
            Arguments:
                x {float | int} -- Independent Variable
                y {float | int} -- Dependent Variable
            
            Returns:
                float -- Cost (or error)
        '''

        cost = 0
        
        for i in range(len(x)):
            cost += ((y[i] - self.predict(x[i])) ** 2)

        return (cost / float(len(x)))

    
    def generate_batches(self, x, y, batch_size):
        '''
            Generate Batches of Data to fit model.
            
            Arguments:
                x {float | int} -- Values (array) of Independent Variable
                y {float | int} -- Values (array) of Dependent Variable
                batch_size {int} -- Size of each batch on Data.
        '''

        num_points = len(x)

        idx = np.random.permutation(num_points)
        batches = range(0, num_points - batch_size + 1, batch_size)

        for batch in batches:
            X_mini = x[idx[batch:batch + batch_size]]
            y_mini = y[idx[batch:batch + batch_size]]

            yield (X_mini, y_mini)

    def derivative(self, x, y):
        '''
            Calculate Derivative of Cost (or Error) w.r.t m and c variable.

            m_derivative = -2x(y - yhat)
            c_derivate = -2(y - yhat)
            
            Arguments:
                x {float | int} -- Value of Independent Variable
                y {float | int} -- Value of Dependent Variable
            
            Returns:
                Tuple -- Tuple of Derivatives.
        '''

        y_hat = self.predict(x)

        dJ_m = -2 * (x * (y - y_hat))
        dJ_c = -2 * (y - y_hat)

        return (dJ_m, dJ_c)

    def update_parameters(self, x, y):
        '''
            Update the Parameters (i.r Variable m and c).
            Parameter are updates as follow:
                m = m - ((m_derivative / N) * lr)
                c = c - ((c_derivative / N) * lr)
            
            Arguments:
                x {float | int} -- Values (array) of Independent Variable
                y {float | int} -- Values (array) of Dependent Variable
        '''

        m_derv = 0
        c_derv = 0

        for i in range(len(x)):
            dJ = self.derivative(x[i], y[i])

            m_derv += dJ[0]
            c_derv += dJ[1]

        self.m -= ((m_derv / float(len(x))) * self.lr)
        self.c -= ((c_derv / float(len(x))) * self.lr)

    def fit(self, X, y, epochs = 5, batch_size = 10):
        '''
            Fit the data.
            
            Arguments:
                X {float | int} -- Values (array) of Independent Variable
                y {float | int} -- Values (array) of Dependent Variable
            
            Keyword Arguments:
                epochs {int} -- Number of Training Epochs (default: {5})
                batch_size {int} -- Size of the Batch (default: {10})
        '''

        loss = 0
        
        for e in range(epochs):
            loss = 0
            for (batch_x, batch_y) in self.generate_batches(X, y, batch_size):
                loss = self.cost(batch_x, batch_y)

                self.update_parameters(batch_x, batch_y)

            print (f"Epoch: {e+1} - Loss: {loss}")


if __name__ == "__main__":
    X = np.linspace(start = 1, stop = 100 , num = 100)
    y = 12 * X

    grad = GradientDescent(lr = 0.0001)
    grad.fit(X, y, epochs = 10)

    print (f"Weight: {grad.m} & Bias: {grad.c}")