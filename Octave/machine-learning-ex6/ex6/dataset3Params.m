function [C, sigma] = dataset3Params(X, y, Xval, yval)
%DATASET3PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = DATASET3PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.
C = 100;
sigma = 0.3;

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
%

test_values = [0.01, 0.03, 0.1, 0.3, 1, 3, 10, 30];

test_outputs = [];

for i = 1:length(test_values),
	for j = 1:length(test_values),
	
		C_vec = test_values(i);
		sigma_vec = test_values(j); 
	
		model = svmTrain(X, y, C_vec, @(x1, x2) gaussianKernel(x1, x2, sigma_vec));
		predictions = svmPredict(model, Xval);
		
		test_error = mean(double(predictions ~= yval));
		
		fprintf("C: %f\nsigma: %f\ntest_error: %f\n", C_vec, sigma_vec, test_error);
		test_outputs = [test_outputs; C_vec, sigma_vec, test_error];
		
	end
end	

[optimal_error,Index] = min(test_outputs(:,3)); 

C = test_outputs(Index,1);
sigma = test_outputs(Index,2);

fprintf("\n\nOptimal values \nC: %f\nsigma: %f\ntest_error_minimum %f\n",C, sigma, optimal_error);


% =========================================================================

end
