function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples
n= size(theta);
% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta

sum=0;
sum1=0;
p= X*theta;
predictions = sigmoid(p);
for  i=1:m
    sum= sum + ((y(i,1)*log(predictions(i,1))) + ((1-y(i,1))*log(1 - predictions(i,1))));
end
for i=2: n
  sum1=sum1 + (theta(i,1) * theta(i,1));
end


J= ((-1/m)*(sum)) + ((lambda/(2*m))* (sum1));

 grad = (1/m)*(((predictions-y)' * X)');

 for i=2:n
   grad(i,1) = grad(i,1) + ((lambda/m)*(theta(i,1)));
 end
 

% =============================================================

end
