function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%
%==============================================================================|
%---------------Part-1:-Feedforward Propagation of Neural Network--------------|
%-------------------------Un-regularized form----------------------------------|
X = [ones(m,1) X];

%a1 = X;                                       %But we are directly using a1 as X for a2
%input layer propagation
a2 = sigmoid(Theta1*X');
	
%Updated value after add bias to hidden layer 
a2 = [ones(m,1) a2'];
	
%hidden layer feedforward propregation 
h = sigmoid(Theta2 * a2');                 %h = a3, since a3 is our final output

%----------------------------------
%{recall that whereas the original labels (in the variable y) were 1, 2, ..., 10, for the purpose of training a neural  network, we need to recode the labels as vectors containing only values 0 or 1 
%}
Y = zeros(num_labels, m); 
for i = 1:m,
	Y(y(i),i)=1;
end
 
%cost function:- 
%vectorized implementation
%NOTE:- In Neural network matrix multiplication for cost function is a scaler multiplication
 
J = (1/m) * [trace((-Y)'*log(h)) -  trace((1 - Y)'* log(1 - h))];     %op1 is 5000x10, op2 is 5000x10) so element-wise multiplication, We can also use trace sum like 'trace(A.*A)'  ...Reference:- Discussion Forum

%------------------------------------------------------------------------------|
%----------------------------Regularized form----------------------------------|
%{Notice that we can first compute the unregularized cost function J using your existing nnCostFunction.m and then later add the cost for the regularization terms. Note that you should not be regularizing the terms that correspond to the bias. For the matrices Theta1 and Theta2, this corresponds to the first column of each matrix %}

%We are explicitly excluding bias term theta_zero
theta1 = Theta1(:,2:size(Theta1,2));
theta2 = Theta2(:,2:size(Theta2,2));

%extra regularization term
Regulariz = lambda  * (sum( sum ( theta1.^ 2 )) + sum( sum ( theta2.^ 2 ))) / (2*m);

%Regularized cost function 
J = J + Regulariz;

%===============================================================================|
%---------------------Part-2:-< Back Propagation >------------------------------|
for t = 1:m,
    %-----Step-1:---------------------------------------------------------------
	a1 = X(t,:);                                         % X, We have already biased
    
    %-----Step-2:-Forward Propagation-------------------------------------------
	z2 = Theta1*a1';
	a2 = sigmoid(z2);                          % here a2 = sigmoid(z2), where z2 = Theta1*a1' ,since a1 = X 
	
	a2 = [1 a2'];                             % bising
	
	z3 = Theta2*a2';                            %Theta2*a2' it's giving error,      
	a3 = sigmoid(z3);                          % here, h = a3 = sigmoid(z3), where z3 = Theta2*a2'
   
    %--------------------Back Propagation---------------------------------------
    z2 = [1 ; z2];                                 % bias
    
    
    %-----Step-3:-using y(t) to compute,“error term” δjth node of lth layer-----
    del_3 = a3 - Y(:, t);                                 %Y is y of kth unit in output layer

    %-----Step-4:-compute inernal errors----------------------------------------
    
    del_2 = (Theta2'*del_3) .* sigmoidGradient(z2);%here,Edited..Theta1*a1' is nothing but z2
    % Excluding(removing) del_2(0) 
	del_2 = del_2(2 : end);
	 
    %-----Step-5:-Finally, Hence we update our new Delta matrix-------------------------------------
   
    Theta2_grad = Theta2_grad + del_3 * a2;
    Theta1_grad = Theta1_grad + del_2 * a1;
     
end;
% Obtain the (unregularized) gradient for the neural network cost function by dividing the accumulated gradients by m:

%Theta1_grad = Theta1_grad ./m;
%Theta2_grad = Theta2_grad ./m;

% ==============================================================================|
%-----------Part-3:-Implement regularization with the cost function and gradients.---|
Theta1_grad(:,1)     = Theta1_grad(:,1) ./m;  				             %for j = 0, But in octave j = 1
Theta1_grad(:,2:end) = Theta1_grad(:,2:end) ./m + ((lambda/m)*Theta1(:,2:end));%for j>0,and then j=2:end   

Theta2_grad(:,1)     = Theta2_grad(:,1) ./m;  				             %For same conditions as above
Theta2_grad(:,2:end) = Theta2_grad(:,2:end) ./m + ((lambda/m)*Theta2(:,2:end));        


% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];

end

%{
function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%
%==============================================================================|
%---------------Part-1:-Feedforward Propagation of Neural Network--------------|
%-------------------------Un-regularized form----------------------------------|
X = [ones(m,1) X];

%a1 = X;                                       %But we are directly using a1 as X for a2
%input layer propagation
a2 = sigmoid(Theta1*X');
	
%Updated value after add bias to hidden layer 
a2 = [ones(m,1) a2'];
	
%hidden layer feedforward propregation 
h = sigmoid(Theta2 * a2');                 %h = a3, since a3 is our final output

%----------------------------------
%{recall that whereas the original labels (in the variable y) were 1, 2, ..., 10, for the purpose of training a neural  network, we need to recode the labels as vectors containing only values 0 or 1 
%}
%{
Y = zeros(num_labels, m); 
for i = 1:m,
	Y(y(i),i)=1;
end
 
%cost function:- 
%vectorized implementation
%NOTE:- In Neural network matrix multiplication for cost function is a scaler multiplication
 
J = (1/m) * [trace((-Y)'*log(h)) -  trace((1 - Y)'* log(1 - h))];     %op1 is 5000x10, op2 is 5000x10) so element-wise multiplication, We can also use trace sum like 'trace(A.*A)'  ...Reference:- Discussion Forum

%------------------------------------------------------------------------------|
%----------------------------Regularized form----------------------------------|
%{Notice that we can first compute the unregularized cost function J using your existing nnCostFunction.m and then later add the cost for the regularization terms. Note that you should not be regularizing the terms that correspond to the bias. For the matrices Theta1 and Theta2, this corresponds to the first column of each matrix %}

%We are explicitly excluding bias term theta_zero
theta1 = Theta1(:,2:size(Theta1,2));
theta2 = Theta2(:,2:size(Theta2,2));

%extra regularization term
Regulariz = lambda  * (sum( sum ( theta1.^ 2 )) + sum( sum ( theta2.^ 2 ))) / (2*m);

%Regularized cost function 
J = J + Regulariz;

%===============================================================================|
%---------------------Part-2:-< Back Propagation >------------------------------|
for t = 1:m,
    %-----Step-1:---------------------------------------------------------------
	a1 = X(t,:);                                         % X, We have already biased
    
    %-----Step-2:-Forward Propagation-------------------------------------------
	z2 = Theta1*a1';
	a2 = sigmoid(z2);                          % here a2 = sigmoid(z2), where z2 = Theta1*a1' ,since a1 = X 
	
	a2 = [1 a2'];                             % bising
	
	z3 = Theta2*a2';                            %Theta2*a2' it's giving error,      
	a3 = sigmoid(z3);                          % here, h = a3 = sigmoid(z3), where z3 = Theta2*a2'
   
    %--------------------Back Propagation---------------------------------------
    z2 = [1 ; z2];                                 % bias
    
    
    %-----Step-3:-using y(t) to compute,“error term” δjth node of lth layer-----
    del_3 = a3 - Y(:, t);                                 %Y is y of kth unit in output layer

    %-----Step-4:-compute inernal errors----------------------------------------
    
    del_2 = (Theta2'*del_3) .* sigmoidGradient(z2);%here,Edited..Theta1*a1' is nothing but z2
    % Excluding(removing) del_2(0) 
	del_2 = del_2(2 : end);
	 
    %-----Step-5:-Finally, Hence we update our new Delta matrix-------------------------------------
   
    Theta2_grad = Theta2_grad + del_3 * a2;
    Theta1_grad = Theta1_grad + del_2 * a1;
     
end;
% Obtain the (unregularized) gradient for the neural network cost function by dividing the accumulated gradients by m:

%Theta1_grad = Theta1_grad ./m;
%Theta2_grad = Theta2_grad ./m;

% ==============================================================================|
%-----------Part-3:-Implement regularization with the cost function and gradients.---|
Theta1_grad(:,1)     = Theta1_grad(:,1) ./m;  				             %for j = 0, But in octave j = 1
Theta1_grad(:,2:end) = Theta1_grad(:,2:end) ./m + ((lambda/m)*Theta1(:,2:end));%for j>0,and then j=2:end   

Theta2_grad(:,1)     = Theta2_grad(:,1) ./m;  				             %For same conditions as above
Theta2_grad(:,2:end) = Theta2_grad(:,2:end) ./m + ((lambda/m)*Theta2(:,2:end));        


% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];

end

%}
