using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		int temp,i=1;
		multiset <int> st;
		multiset <int>:: reverse_iterator it;
		while(n--)
		{
			if(i<k)
			{
				cin>>temp;
				st.insert(temp);
				cout<<-1<<" ";
				i++;
			}
			else
			{
				cin>>temp;
				st.insert(temp);
				it=st.rbegin();
				int j=1;
				while(j<k)
				{
					it++;
					j++;
				}
				cout<<(*it)<<" ";
			}
		}
		cout<<endl;
	}
}
