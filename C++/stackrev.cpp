#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int>s;
	queue<int>q;
	for(int i=1;i<=10;i++)
	{
		s.push(i);
	}
	
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
}
