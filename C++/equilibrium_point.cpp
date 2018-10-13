using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int left = 0, sum = 0;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin>>arr[i];
	        sum += arr[i];
	    }
	    int flag = 0;
	    for(int i = 0; i < n; i++)
	    {
	        sum -= arr[i];
	        if(left == sum)
	        {
	            cout<<i+1<<"\n";
	            flag = 1;
	            break;
	        }
	        left += arr[i];
	    }
	    if(!flag)
	    {
	        cout<<"-1\n";
	    }
	}
	return 0;
}