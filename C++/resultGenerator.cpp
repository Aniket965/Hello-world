#include<iostream>
class student
{
private:
    int maths,ca,oops,net,fa,sum,choice;
    float per,avg;
public:
    void ed();
    int total();
    int percentage();
    int avgerage();
    int dd(int,int,int);
};

void student::ed()
{
    std::cout << "Enter Marks in maths: ";
    std::cin >> maths;
    std::cout << "Enter Marks in CA : ";
    std::cin >> ca;
    std::cout << "Enter Marks in OOPS: ";
    std::cin >> oops;
    std::cout << "Enter Marks in .Net: ";
    std::cin >> net;
    std::cout << "Enter Marks in FA";
    std::cin >> fa;
    std::cout <<"1)Total"<<'\n';
    std::cout <<"2)Average" << '\n';
    std::cout <<"3)Percentage"<< '\n';
    std::cout <<"Enter Your choice :";
    std::cin>>choice;
}

int student::dd(int sum,int avg,int per)
{
    if(choice==1)
        std::cout << sum << '\n';
    else if (choice==2) {
        std::cout << avg << '\n';
    }

    else if (choice==3) {
        std::cout << per << '\n';
    }
    else
        std::cout << "Invalid choice" << '\n';
}

int student::total()
{
    sum=maths+ca+oops+fa+net;
    return sum;
}

int student::percentage()
{
    per=(sum/500)*100;
    return per;
}

int student::avgerage()
{
    avg=sum/500;
    return avg;
}

int main()
{
    student s1;
    int sum;
    float per,avg;
    s1.ed();
    per=s1.percentage();
    sum=s1.total();
    avg=s1.avgerage();
    s1.dd(sum,avg,per);
}
