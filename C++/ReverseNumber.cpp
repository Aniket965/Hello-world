#include<iostream>
using namespace std;
class rev
{
	private:
			int num,n1,n2,rn=0;
	public:
			void enterData();
			void calc();
			void display();
};
void rev::enterData()
{
	cout<<"Enter a 2-Digit No.:";
	cin>>num;
}
void rev::calc()
{
	n1=num/10;
	n2=num%10;
	rn=n2*10+n1;
}
void rev::display()
{
		cout<<"Reverse of "<<num<<" is "<<rn<<endl;
}
int main ()
{
	rev r;
	r.enterData();
	r.calc();
	r.display();
}
