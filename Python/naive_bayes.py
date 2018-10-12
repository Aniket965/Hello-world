import scipy as sp
import numpy as np


# Do the bayes thing
def bayes_single(data, v):
    sigma = sp.var(data)
    mu = sp.average(data)
    return sp.e ** (-1 * (v - mu) ** 2 / (2 * sigma)) / np.sqrt(2 * sp.pi * sigma)


# Do a bayes on an array of arrays
def bayes(data, v, P_c):
    ret = P_c
    # Assuming read values have the same dimensions as input values
    for i in range(0, len(v)):
        ret *= bayes_single(data[i], v[i])
    return ret


# Read data.txt into input_data
f = open('data.txt', 'r')
input_data = np.loadtxt(f)
input_data = input_data[input_data[:, 0].argsort()]

# dim and data_size stay constant throughout the program
dim = input_data.max(axis=0)
data_size = len(input_data)

# Make lists of data according to each dimension
data_list = np.split(input_data, np.where(np.diff(input_data[:, 0]))[0] + 1)

# Remove dimension data
for i in range(0, len(data_list)):
    data_list[i] = np.swapaxes(data_list[i], 1, 0)
    data_list[i] = np.delete(data_list[i], 0, axis=0)

# Get requested calculations
requested = np.zeros(len(data_list[0]))
for i in range(0, len(requested)):
    requested[i] = input('Enter ' + chr(88 + i) + ': ')

# Print out answer to calculations
for i in range(0, len(data_list)):
    print('Class ' + str(i) + ' probability: ' + str(bayes(data_list[i],
                                                           requested,
                                                           len(data_list[i]) / data_size)))
