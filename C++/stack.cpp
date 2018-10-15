#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<int> s;

  for(int i=0;i<10;i++)
  {
    s.push(i);
  }
  while(s.empty() !=1)
  {
    int t=s.top();
    s.pop();
    cout << t <<endl;
  }
  return 0;
}
