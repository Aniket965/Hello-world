At its core, PyTorch provides two main features:

  -  An n-dimensional Tensor, similar to numpy but can run on GPUs
  -  Automatic differentiation for building and training neural networks

Pytorch uses dynamic computation graphs, as opossed to tensorflow (although tensorflow has now introduced eager execution, which provides similar functionality to dynamic graphs in pytorch), where a computation graph must be specified in advance.

We will use a fully-connected ReLU network as our running example. The network will have a single hidden layer, and will be trained with gradient descent to fit random data by minimizing the Euclidean distance between the network output and the true output.
