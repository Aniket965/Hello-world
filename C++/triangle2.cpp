#include <iostream>
using namespace std;
int main(){
	cout<<"Enter the triangle height:";
	int high;
	cin>>high;
	for(int i=0;i<high;i++){
		for(int s=0;s<(high-i);s++)
		{
			cout<<" "; 
		}
		for(int j=0;j<=i;j++){
			cout<<"* ";
		}
		cout<<endl;
	}

}
