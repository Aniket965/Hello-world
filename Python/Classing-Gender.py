#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Classing gender by height, weight, shoes_size

from sklearn import tree

clf = tree.DecisionTreeClassifier()
# [height, weight, shoe_size]
X = [[181, 80, 44], [177, 70, 43], [160, 60, 38], [154, 54, 37], [166, 65, 40],
     [190, 90, 47], [175, 64, 39],
     [177, 70, 40], [159, 55, 37], [171, 75, 42], [181, 85, 43], [176, 65, 42]]

Y = ['male', 'male', 'female', 'female', 'male', 'male', 'female', 'female',
'female', 'male', 'male', 'male']

# Train
clf = clf.fit(X, Y)

# Get Information
a = input("Height: ")
b = input("Weight: ")
c = input("Shoe Size: ")

# Make Prediction
prediction = clf.predict([[190, 70, 43]])

# Print the result
print(prediction[0])
