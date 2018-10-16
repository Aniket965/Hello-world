#include<iostream>;
using namespace std;
void swap(int *p1,int *p2)
{
  int c=*p2;
  *p2=*p1;
  *p1=c;
}
int main()
{int x1,x2;
cin>>x1>>x2;
    int *p1=&x1;
    int *p2=&x2;
    swap(p1,p2);
   cout<<"x1"<<x1<<endl;
    cout<<"x2"<<x2<<endl;

}
