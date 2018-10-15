#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int x);

int main() {
	int number;
	bool result;
	setlocale(LC_ALL, "rus");
	
	cout << endl;
	cout << "Numbers <= 0 are not considered in this program" << endl <<
		"1 is nor Prime nor Composite number." << endl;
	cout << endl;

	try {
		cout << "Enter your number : " << endl;
		cin >> number;
		if (cin.fail() or (number <= 1)) throw -1;

		result = is_prime(number);

		if (result) cout << "Number " << number << " is Prime." << endl;
		else cout << "Number " << number << " is Composite." << endl;
	}
	catch (...) {
		cout << "Data is not correct." << endl;
		return -1;
	}
	return 0;
}

bool is_prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}
