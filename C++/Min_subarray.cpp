#include <iostream>

using namespace std;


#define Max 1000000007


int main() {
	// min keeps track of minnimum sum untill previous iteration 
	// curr_min keeps track of current sum in present iteration 
	int n, min= Max, curr_min=Max;

	cout<<"Enter number of elements: ";

	cin>>n;

	int a[n];

	cout<<"Enter Elements :";

	for(int i=0;i<n;i++){

		cin>>a[i];

	}


	for(int i=0; i<n; i++){
		// If curr_min is greater than 0 then set it to a[i] as we need the min sum 
		if(curr_min >0 ){

			curr_min = a[i];

		}

		else{
			// If not positive then add element to it to get sum of subarray
			curr_min+=a[i];

		}
		// Update min if curr_min becomes less than min 
		min = min < curr_min?min:curr_min;

	}

	
cout<<"Min Sum is : "<<min<<"\n";

	return 0;

}
