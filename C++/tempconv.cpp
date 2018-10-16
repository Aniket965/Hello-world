#include<iostream>
using namespace std;
class tempConv
{
private:
    int fahre,cal;
public:
    void enterData();
    int conversion();
};

void tempConv::enterData()
{
  std::cout << "Enter temprature in Fahrenheit: ";
  std::cin >> fahre;
}

int tempConv::conversion()
{
  cal=(fahre-32)/1.8;
  return cal;
}

int main()
{
  int data;
  tempConv temp;
  temp.enterData();
  data=temp.conversion();
  cout <<"temprature in Celsius: "<<data<<endl;
  return data;
}
