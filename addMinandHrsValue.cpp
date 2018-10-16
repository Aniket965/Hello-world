#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    void enterData();
    void display();
    void addTime(Time T1,Time T2);
};

void Time::enterData()
{
    cout << "Enter time:" << endl;
    cout << "Hours? ";    cin>>hours;
    cout << "Minutes? ";  cin>>minutes;
    cout << "Seconds? ";  cin>>seconds;
}

void Time::display()
{
    cout << endl;
    cout << "Time after add: ";
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

void Time::addTime(Time T1,Time T2)
{

    seconds=T1.seconds+T2.seconds;
    minutes=T1.minutes+T2.minutes+(seconds/60);
    hours= T1.hours+T2.hours +(minutes/60);
    minutes %=60;
    seconds %=60;
}


int main()
{
    Time T1,T2,T3;
    T1.enterData();
    T2.enterData();
    T3.addTime(T1,T2);
    T3.display();

    return 0;
}
