import tflearn
from tflearn.layers.core import input_data, dropout, fully_connected
from tflearn.layers.conv import conv_2d, max_pool_2d
from tflearn.layers.normalization import local_response_normalization
from tflearn.layers.estimator import regression
import tensorflow as tf
import pandas as pd
import numpy as np
import random
from time import sleep
from sklearn.preprocessing import OneHotEncoder
from sklearn.cross_validation import train_test_split
from math import sqrt
import matplotlib.pyplot as plt

def initialize_model(lr):
    net = input_data(shape=[None, 28, 28, 1])
    net = local_response_normalization(net)
    net = conv_2d(net, 32, 3, activation='relu', regularizer="L2")
    net = max_pool_2d(net, 2)
    net = local_response_normalization(net)
    net = conv_2d(net, 64, 3, activation='relu', regularizer="L2")
    net = max_pool_2d(net, 2)
    net = local_response_normalization(net)
    net = conv_2d(net, 64, 3, activation='relu', regularizer="L2")
    net = max_pool_2d(net, 2)
    net = local_response_normalization(net)
    net = conv_2d(net, 128, 3, activation='relu', regularizer="L2")
    net = max_pool_2d(net, 2)
    net = local_response_normalization(net)
    net = fully_connected(net, 128, activation='relu')
    net = dropout(net, 0.8)
    net = fully_connected(net, 64, activation='relu')
    net = dropout(net, 0.8)
    net = fully_connected(net, 10, activation='softmax')
    net = regression(net, optimizer='adam', learning_rate=lr, loss='categorical_crossentropy')
    model = tflearn.DNN(net)
    return model

def load_data(path):
    data=pd.read_csv(path)
    X=data.iloc[:,1:].values.reshape([-1,28,28,1])
    y=data.iloc[:,0].values
    y=y.reshape(y.shape[0],1)
    enc=OneHotEncoder(categorical_features=[0])
    y=enc.fit_transform(y).toarray()
    return X, y

def train_model(X, y, epo):                        
    model.fit(X, y, n_epoch=epo, show_metric=True)
    return model

def render_img(data):
    pxl=int(sqrt(len(data)))
    data=data.reshape(pxl,pxl)
    plt.imshow(data)
    
def get_accuracy(pred, y):
    pred=np.argmax(pred, axis=1)
    acc=0
    for prediction, actual in zip(pred, y):
        if prediction==actual:
            acc+=1
    return pred, acc/len(y)*100 

def show_predicted_samples(n_samples, y_val, X_val):
    for img in range(n_samples):
        i=random.randrange(0,len(y_val))
        render_img(X_val[i])
        print("Image number",img+1)
        print("Predicted: {}".format(model.predict([X_val[i]])))
        print("Actual: {}".format(y_val[i][0]))
        sleep(2)
        
def create_submission(path):
    X_test=pd.read_csv('test.csv').values.reshape([-1,28,28,1])
    pred=[]
    for i in range(28000):
        res=model.predict([X_test[i]])
        pred.append(res[0])
        if i%1000==0:
            print("Testing example number:",i)
    pred=np.argmax(pred, axis=1).reshape(len(pred), 1)  
    submission=np.arange(1, 28001)
    submission=submission.reshape(len(submission), 1)
    submission=np.concatenate((submission, pred), axis=1)
    df=pd.DataFrame(data=submission, columns=['ImageId','Label'])
    df.to_csv(path, index=False) 
    
        
   

if __name__=='__main__':
    #import os
    #os.environ['CUDA_VISIBLE_DEVICES']='-1'
    X, y=load_data('train.csv')
    X_train, X_val, y_train, y_val=train_test_split(X, y, test_size=0.2, random_state=0)
    tf.reset_default_graph()
    model=initialize_model(lr=0.0001)
    model=train_model(X_train, y_train, epo=20)
    #model.load('model_v1.tflearn')
    accuracy=model.evaluate(X_val, y_val)
    #pred, accuracy=get_accuracy(pred, y_val)
    print('accuracy', accuracy)
    create_submission('submission_v6.csv')
    
       
    
