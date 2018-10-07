#include <iostream>
using namespace std;

#define MAX 5

class queue {
public:
    int front,rear;
    int arr[5];
    
    queue() {
        front=rear=-1;
    }
    
    void push(int x) {
        if(front-rear==1 ) {
            cout<<"Queue Overflow";
            return;
        }
        if(front==0 && rear==MAX) {
            cout<<"Queue Overflow";
            return;
        }
        if(rear==-1) {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        rear=rear%MAX;
        arr[rear]=x;
    }
    
        int pop() {
            if(front==-1) {
                cout<<"Queue Underflow";
                return 0;
            }
            if(front==rear) {
                int x= arr[front];
                front=rear=-1;
                return  x;
            }
            
            int x=arr[front];
            front++;
            front=front%MAX;
            return x;
        }
};


int main() {
    queue q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"Element is "<<q.pop()<<endl;
    q.push(5);
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
    cout<<"Element is "<<q.pop()<<endl;
    
    
}
