#include<stdio.h>

int n,arr[200005],ans,curSum;

int main(){
	// Reading size of array and array.
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);


	for(int i=1;i<=n;i++){

		// Add i'th value to current summary.
		curSum += arr[i];

		// When current summary becomes negative we should assign zero because adding to negative value isn't logical.
		if(curSum < 0){
			curSum = 0;
		}

		// Every for loops we should maximaze the answer.
		if(ans < curSum)
			ans = curSum;
	}

	printf("%d\n",ans);
}
