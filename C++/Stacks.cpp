#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class stack
{
  public:
    node *top;
    stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        node *ptr = new node;
        ptr->data = x;
        ptr->next = nullptr;
        if (top != nullptr)
            ptr->next = top;
        top = ptr;
    }

    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow\n";
            return 0;
        }
        int data = top->data;
        auto current = top;
        top = top->next;
        delete current;
        return data;
    }

    void show()
    {
        if (top != nullptr)
        {
            auto current = top;
            while (current != nullptr)
            {
                std::cout << current->data;
                if (current->next != nullptr)
                {
                    std::cout << ">>";
                }

                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.show();
    cout << "Element is " << s.pop() << endl;
    cout << "Element is " << s.pop() << endl;
    cout << "Element is " << s.pop() << endl;
    cout << "Element is " << s.pop() << endl;
    return 0;
}
