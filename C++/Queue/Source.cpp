#include<iostream>
#include "Queue.cpp"

using namespace std;

int main() {
	Queue<int>Q;
	Q.push(5);
	Q.push(6);
	Q.pop();
	Q.push(7);
	cout << Q.Front() << endl << Q.length() << endl ;



	system("pause");


	return 0;
}
