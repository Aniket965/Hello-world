using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		int low = 0;
		int mid = 0;
		int hi = n - 1;
		while(mid <= hi)
		{
			switch(arr[mid])
			{
				case 0: swap(arr[mid++], arr[low++]);
						break;
						
				case 1: mid++;
						break;
						
				case 2: swap(arr[mid], arr[hi--]);
						break;		
			}
		}
		for(int i = 0; i < n; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}