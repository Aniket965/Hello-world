#include<iostream>
using namespace std;
class abc
{
public:
    virtual void show()
    {
        cout<<"Base\n";
    }
};
class derived:public abc
{
public:
    void show() override
    {
        cout<<"Derived\n";
    }
};
int main()
{
    abc *p;
    abc ob;
    p=&ob;
    p->show();
    derived ob1;
    p=&ob1;
    p->show();
    return 0;

}
