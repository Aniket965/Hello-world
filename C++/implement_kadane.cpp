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
	    int max = INT_MIN;
	    int max2 = 0;
	    for(int i = 0; i < n; i++)
	    {
	        max2 = max2 + arr[i];
	        if(max < max2)
	        {
	            max = max2;
	        }
	        if(max2 < 0)
	        {
	            max2 = 0;
	        }
	    }
	    cout<<max<<"\n";
	}
	return 0;
}