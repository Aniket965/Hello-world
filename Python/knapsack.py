### Famous Knapsack Problem

# Sample Test
value = [60, 100, 120] 
weight = [10, 20, 30] 
max_capacity = 50
n = len(value) 


def knapSack(max_capacity , weight , value , n): 

	# what if max weight is 0  
	if n == 0 or max_capacity == 0 : 
		return 0

	if (weight[n-1] > max_capacity): 
		return knapSack(max_capacity , weight , value , n-1) 

	# returns the maximum of two cases: 
	else: 
		return max(value[n-1] + knapSack(max_capacity-weight[n-1] , weight , value , n-1), 
				knapSack(max_capacity , weight , value , n-1)) 

if __name__ == '__main__':
	print knapSack(max_capacity, weight, value, n)
