import numpy as np
#define tanh activation function
def tanh(x, deriv=False):
    if deriv:
        return 1 - x**2
    return np.tanh(x)


def add_dim(x):
    return np.reshape(x, (len(x), 1))

#defining softmax activation 
def softmax(x):
    e_x = np.exp(x - add_dim(np.max(x, axis=1)))
    return e_x/add_dim(np.sum(e_x, axis=1))

def train(inputs, outputs, layers, max_weights=0.1, learning_rate=0.05, epochs=100):
    input_size = inputs.shape[1]
    output_size = outputs.shape[1]
    weights = [(max_weights * np.random.randn(layers[i], layers[i + 1])) - (max_weights * 2)
               for i in range(len(layers) - 1)]
    biases = [np.zeros((layers[i + 1])) for i in range(len(layers) - 1)]

    layer_vals = [inputs]
    
    for _ in range(epochs):
      for i in range(len(layers) - 1):
          prev_layer = layer_vals[-1]
          new_layer = np.dot(prev_layer, weights[i]) + biases[i]
          if i == len(layers) - 2:
              new_layer = softmax(new_layer)
          else:
              new_layer = tanh(new_layer)
          layer_vals.append(new_layer)
      output = layer_vals[-1]

      loss = -np.sum(np.multiply(np.log(output), outputs))/len(inputs)
      print(loss)
      deriv =  output - outputs
      for i in range(len(layers) - 2, 0, -1):
          dW = np.dot(layer_vals[i].T, deriv) / len(inputs)
          dB = np.sum(deriv, axis=0) / len(inputs)
          deriv = tanh(np.dot(deriv, weights[i].T), deriv=True)
          weights[i] -= learning_rate * dW
          biases[i] -= learning_rate * dB
    return weights, biases
