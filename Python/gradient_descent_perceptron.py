import numpy as np
import random
import sys
from copy import deepcopy

def recall(weights, data, labels, length):
    count = 0
    for i in xrange(length):
        h = np.sign(np.dot(weights, data[i]))
        if int(h) == int(labels[i]) and int(h) == 1:
            count += 1

    total = sum(labels[labels == 1])
    if not total == 0:
        return count / (total * 1.0)
    else:
        return 0

def precision(weights, data, labels, length):
    count = 0
    total = 0
    for i in xrange(length):
        h = np.sign(np.dot(weights, data[i]))
        if int(h) == int(labels[i]) and int(h) == 1:
            count += 1
            total += 1
        elif int(h) != int(labels[i]) and int(h) == 1:
            total += 1

    if total != 0:
        return count / (total * 1.0)
    else:
        return 0

train = sys.argv[1]
test = sys.argv[2]

random.seed(10)

# temp_arr = []

# for i in xrange(len(np_df)):
#     if not np.isnan(np_df[i, 6]):
#         np_df[i, 6] = int(np_df[i, 6])
#         temp_arr.append(np_df[i, 6])

# question_replacer = int(np.median(temp_arr))

# for i in xrange(len(np_df)):
#     if np.isnan(np_df[i, 6]):
#         np_df[i, 6] = question_replacer

# temp_arr = []

# for i in xrange(len(test_set)):
#     if not np.isnan(test_set[i, 6]):
#         test_set[i, 6] = int(test_set[i, 6])
#         temp_arr.append(test_set[i, 6])

# question_replacer = int(np.median(temp_arr))

# for i in xrange(len(test_set)):
#     if np.isnan(test_set[i, 6]):
#         test_set[i, 6] = question_replacer

# np_df = np.delete(np_df, [0, 10], axis = 1)
# test_set = np.delete(test_set, [0], axis = 1)

# np_df = np_df.astype('float')
# test_set = test_set.astype('float')

# mean = np.mean(np_df)
# np_df = np_df - mean

# mean = np.mean(test_set)
# test_set = test_set - mean

# np_df = np.multiply(np_df, 1/float(np.var(np_df) / float(np.var(np_df))))
# test_set = np.multiply(test_set, 1/float(np.var(test_set)) / float(np.var(test_set)))

# b = np.ones((len(np_df), 1))
# c = np.ones((len(test_set), 1))

# np_df = np.append(np_df, b, axis=1)
# test_set = np.append(test_set, c, axis=1)

# print np_df[0]

# cost = 100
# newcost = 10
# num = 0
# while(1):
#   num += 1
#   cost = newcost
#   newcost = 0
#   inputs = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
#   for i in xrange(len(np_df)):
#       res = predict(np_df[i], weights)
#       if not res == labels[i]:
#           if labels[i] == 0:
#               newcost += abs(np.matmul(np_df[i], np.transpose(weights)))
#               inputs = np.add(np_df[i], inputs)
#           else:
#               newcost += abs(np.matmul(np_df[i], np.transpose(weights)))
#               inputs = np.add(inputs, np.multiply(-1, np_df[i]))

#   for i in xrange(len(weights)):
#       weights[i] = weights[i] - learn_rate * inputs[i]

#   if abs(newcost - cost) < 0.00001:
#       print '------>', newcost, cost, abs(newcost - cost), '<------'
#       break
#   if num % 1000 == 0:
#       print newcost, cost, abs(newcost - cost)

# count = 0
# for i in xrange(len(np_df)):
#   res = predict(np_df[i], weights)
#   if res == labels[i]:
#       count += 1

# print 'Accuracy train:', float(count) / len(np_df)

margin = 100
lrdecay = 0.001
decayinterval = 20
batch = False
learning_rate = 1
batchsize = 40

np_df = np.genfromtxt(train, delimiter = ',')

labels = np_df[:, -1]
np_df = np.delete(np_df, [0, 10], axis = 1)
np_df = np_df - 4
np_df = np_df / 10

b = np.ones((len(np_df), 1))
np_df = np.append(np_df, b, axis = 1)

test = np.genfromtxt(sys.argv[2], delimiter = ',')
test = test[:, 1:]
test = test - 4
finaltest = np.ones((test.shape[0], test.shape[1] + 1))
test = test / 10
finaltest[:, : -1] = test

labels -= 3

for opt in xrange(2):
    weights = np.random.normal(0, 0.2, 10)
    best_weights = []
    best_prec = - 1
    batch = False
    best_recall = -1
    if opt == 1:
        batch = True

    for epoch in xrange(100):
        tempsum = 0
        normsum = 0
        for i in xrange(len(np_df)):
            normval = np.linalg.norm(np_df[i])
            if batch == True:
            	if labels[i] * np.dot(weights, np_df[i]) < margin:
            	    normval = normval ** 2
            	    normsum += normval
            	    block = margin - (labels[i] * np.dot(weights, np_df[i]))
            	    update = learning_rate *(labels[i] * (block) * np_df[i])
            	    tempsum += update
            	if i % batchsize == 0 and i != 0:
            	    if normsum == float(0):
            	    	pass
            	    else:
            	        weights += tempsum / normsum
            	    normsum = 0
            	    tempsum = 0
            else:
                if labels[i] * np.dot(weights, np_df[i]) < margin:
                    update = learning_rate *(labels[i] * ((margin - (labels[i] * np.dot(weights, np_df[i]))) / normval) * np_df[i])
                    weights += update

        prec = precision(weights, np_df, labels, len(np_df))
        rec = recall(weights, np_df, labels, len(np_df))
        if opt == 1:
            learning_rate -= lrdecay

        if prec + rec > best_prec + best_recall:
            best_prec, best_recall = prec, rec
            best_weights = weights

    # print best_prec, best_recall

    for i in range(len(finaltest)):
        if int(np.sign(np.dot(best_weights, finaltest[i]))) == 1:
            print 4
        else:
            print 2
