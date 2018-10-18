#include <iostream>
#define SIZE 5   /* Size of Circular Queue */

using namespace std;

class Queue {
private:
    int items[SIZE], front, rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if(front == 0 && rear == SIZE - 1){
            return true;
        }
        if(front == rear + 1) {
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(front == -1) return true;
        else return false;
    }

    void enQueue(int element){
        if(isFull()){
            cout << "Queue is full";
        } else {
            if(front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << endl << "Inserted " << element << endl;
        }
    }

    int deQueue(){
        int element;
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return(-1);
        } else {
            element = items[front];
            if(front == rear){
                front = -1;
                rear = -1;
            } /* Q has only one element, so we reset the queue after deleting it. */
            else {
                front=(front+1) % SIZE;
            }
            return(element);
        }
    }

    void display()
    {
        /* Function to display status of Circular Queue */
        int i;
        if(isEmpty()) {
            cout << endl << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl << "Items -> ";
            for(i=front; i!=rear;i=(i+1)%SIZE)
                cout << items[i];
            cout << items[i];
            cout << endl << "Rear -> " << rear;
        }
    }

};


int main()
{
    Queue q;

    // Fails because front = -1
    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enQueue(6);


    q.display();

    int elem = q.deQueue();

    if( elem != -1)
       cout << endl << "Deleted Element is " << elem;

    q.display();

    q.enQueue(7);

    q.display();

    // Fails to enqueue because front == rear + 1
    q.enQueue(8);

    return 0;
}
