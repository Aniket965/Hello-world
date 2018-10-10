#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSum(vector<int> &arr, int n)
{
    int sum = arr[0], prev = arr[0];
 
    for (int i = 1; i < n; i++) {
 
        // If violation happens, make current
        // value as 1 plus previous value and
        // add to sum.
        if (arr[i] <= prev) {
            prev = prev + 1;
            sum = sum + prev;
        }
 
        // No violation.
        else {
            sum = sum + arr[i];
            prev = arr[i];
        }
    }
 
    return sum;
}

int main() {
	int n, t, first_sum = 0;
	vector<int> v;
	cin>>n;

	for(int i = 0; i < n; ++i){
		cin>>t;
		v.push_back(t);
		first_sum += t;
	}
	
	sort(v.begin(), v.end());
	
	cout<<minSum(v, n) - first_sum;
	
	return 0;
}