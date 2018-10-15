function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESCENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
    h = X * theta;
    
    hmy = (h-y) .* X(:,1);
    hmyx =(h-y) .* X(:,2);
    val = sum(hmy) * (1/m);
    val1 = sum(hmyx) * (1/m);
    temp1 = theta(1) - (alpha * val) ;
    temp2 =  theta(2) - (alpha * val1) ;
    theta(1) = temp1;
    theta(2) = temp2;







    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta);

end

end
