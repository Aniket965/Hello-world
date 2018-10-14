function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta

%Calculating hypothesis function
h = sigmoid(X*theta);

%calculating Cost function 
%We are explicitly excluding bias term theta_zero

theta_featured = [0 ; theta(2: size(theta), :)];
theta_multi = theta_featured'*theta_featured;    %alter element-wise multiplication like -> (A.*A)


J =  (1/m)*[(-(y')*log(h) - (1-y)'*log(1-h)) + (lambda*theta_multi)/2];


%To calculate gradient
grad = (1/m)*(X'*(h-y) + lambda*theta_featured);


%===========================================================

end
