#include <iostream>
using namespace std;

class student
{
  private:
    int a;
  public:
    void enterdata()
    {
        cout <<"Enter value of a:";
        cin >>a;
    }
    friend void findmax(student, student);
};
void findmax(student s1, student s2)
{
    if (s1.a > s2.a)
        cout <<"Data of object s1 is greater"<<endl;
    else if (s1.a < s2.a)
        cout <<"Data of object s2 is greater"<<endl;
    else
        cout <<"Data of object s1 and s2 are equal"<<endl;
}
int main()
{
    student s1,s2;
    cout <<"Enter data for s1"<<endl;
    s1.enterdata();
    cout <<"Enter data for s2"<<endl;
    s2.enterdata();
    findmax(s1, s2);
    return 0;
}
