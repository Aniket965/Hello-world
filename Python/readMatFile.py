import scipy.io
import matplotlib.pyplot as plt

mat = scipy.io.loadmat("olivettifaces")

X = []   
for i in range(40):
    X.append(np.rot90(mat['faces'][:,10*i].reshape(height, width), 3).reshape(1, n))
