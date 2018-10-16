#include <iostream>
using namespace std;
class complex
{
	int real,imag;
	public:
		void get()
		{
			cin>>real>>imag;
		}
		void disp()
		{
			cout<<real<<"+"<<imag<<"i";

		}
		void sum(complex,complex);
};
void complex::sum(complex c1,complex c2)
{
	real=c1.real+c2.real;
	imag=c1.imag+c2.imag;
}
int main()
{
	complex c1,c2,c3;
	cout<<"Enter 1st complex no.:";
	c1.get();
	cout<<"Enter 2nd complex no.:";
	c2.get();
	cout<<"The 1st complex no. is:	";
	c1.disp();
	cout<<"\nThe 2nd complex no. is: ";
	c2.disp();
	c3.sum(c1,c2);
	cout<<"\nThe resultant complex no. is: ";
	c3.disp();

}
