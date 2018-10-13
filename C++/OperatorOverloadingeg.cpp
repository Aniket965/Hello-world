#include<iostream>

using namespace std;

class grocery{
	
	private:
		int no,price,total;
	public:
		grocery(int a,int b)
		{
			no=a;
			price=b;
		}
		operator float(){
			total=price*no;
			return (total);
		}
		
		void display()
		{
			cout<<"Item no \t"<<no;
			cout<<"Rate\t"<<price;
		// 	cout<<"Total\t"<<total;
		}
				
};

int main(){
	
	grocery g(10,15);
	g.display();
	float total=g;
	cout<<"Total="<<total;
	return 0;
}
