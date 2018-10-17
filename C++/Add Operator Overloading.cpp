#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class time{
	
	public:
		int hrs,min,secs;
	
	time(){
		hrs=0;
		min=0;
		secs=0;
	}
	
	public:
		void set(){
			cout<<"\nEnter time in hrs";
			cin>>hrs;
			cout<<"\nEnter time in min";
			cin>>min;
			cout<<"\nEnter time in sec";
			cin>>secs;
			
		}
		
		void show()
		{
			cout<<"\nHours"<<hrs;
			cout<<"\t Mins"<<min;
			cout<<"\t Secs"<<secs;
		}
		time  operator+(time t2);
		time  operator-(time t2);
};
time time::operator+(time t2){
	
	time temp;
	temp.secs=t2.secs+secs;
	temp.min=t2.min+min+((temp.secs)/60);
	temp.hrs=t2.hrs+hrs+((temp.min)/60);
	
	if(temp.secs>=60){
	
	temp.secs=temp.secs%60;}
	
	if(temp.min>=60){
	temp.min=temp.min%60;}
	return temp;
	
}
time time::operator-(time t2){
	if(t2.hrs<hrs){
		cout<<"\nCant Subtract try changing t1 and t2!!!!\n";
		exit(1);
	}
	
	time temp;
	if(t2.secs<secs)
	{
		t2.secs=t2.secs+60;
		t2.min=t2.min-1;
	}
	if(t2.min<min)
	{
		t2.min=t2.min+60;
		--t2.hrs;
	}
	temp.secs=t2.secs-secs;
	temp.min=t2.min-min;
	temp.hrs=t2.hrs-hrs;
	return temp;
	
}

int main(){
	time t1,t2,t3;
	t1.set();
	t2.set();
	t3=t1+t2;
	cout<<"Adding t1 and t2 we get \n";
	t3.show();
	t3=t2-t1;
	cout<<"\nSubtracting t1 from t2 we get \n";
	t3.show();
	getch();
	return 0;	
	
}
