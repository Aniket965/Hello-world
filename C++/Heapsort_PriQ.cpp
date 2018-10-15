@uthor : Ankit Singh


//This is a cpp file that contains max priority queue & heapsort programs both.

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define size 10 //This is the size of heap created.Increase, if required
int heapsize=0; 
using namespace std;

void Max_heapify(int A[],int i)
{
    int left=(2*i)+1,right=(2*i)+2,largest,temp;

    if(left<heapsize && A[left]>A[i])
        largest=left;
    else
        largest=i;
    if(right<heapsize && A[right]>A[largest])
        largest=right;
    if(largest!=i)
    {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        Max_heapify(A,largest);
    }
}
void Build_maxheap(int A[])
{
    heapsize=size;
    int i=(size-2)/2;
    while(i>=0)
    {
        Max_heapify(A,i);
        i--;
    }
}

int heapmax(int A[])
{
    return  A[0];
}
int extractmax(int A[])
{
    if(heapsize<=0)
    {
        printf("Heap Underflow\n");
        //return ;
    }
    else
    {
        int max=A[0];
        A[0]=A[heapsize-1];
        heapsize--;
        Max_heapify(A,0);
        return max;
    }
}
void heapinsert(int A[],int key)
{
    int temp;
    heapsize++;
    int i=heapsize-1;
    A[i]=key;
    while(A[(i-1)/2]<A[i] && i>0)
    {
            temp=A[(i-1)/2];
            A[(i-1)/2]=A[i];
            A[i]=temp;
            i=(i-1)/2 ;
    }
}
void display(int A[])
{
    if(heapsize==0)
        cout<<"Priority Queue Empty\n";
    else
    {
        cout<<"Priority Queue:\n";
        for(int i=0;i<heapsize;i++)
        {
            cout<<A[i] <<" ";
        }
        cout<<endl;
    }
}

void heapsort(int A[])
{
    if(size<1)
        cout<<"Array underflow"<<endl;
    else
    {

        int temp;
        Build_maxheap(A);
        for(int i=size-1;i>0;i--)
        {
            temp=A[0];
            A[0]=A[i];
            A[i]=temp;
            heapsize--;
            Max_heapify(A,0);
        }
    }
}

/*
int main()
{
    //Uncomment this main() & comment the later one to run the heapsort program.

    srand(time(NULL));
    int A[size];
    for(int i=0;i<size;i++)
        A[i]=rand()%100;        //use cin operator if u want to enter your own values instead of random numbers
   
    cout<<"Array:\n";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
        cout<<endl;

    heapsort(A);

    cout<<"Sorted Array:\n";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
        cout<<endl;

}*/

int main()
{
    int ch,x,Q[size];
    while(1)
    {
        cout<<"--------------------\n";
        cout<<"Menu\n1.Enqueue an element\n2.Extract maximum element\n3.Display Queue\nANY OTHER NUMBER TO EXIT\n";
        cout<<"--------------------\n";
        cin>>ch;

        if(ch>3 || ch<=0)
            break;

        switch(ch)
        {
            case 1:
                cout<<"Enter the priority value of the element\n";
                cin>>x;
                heapinsert(Q,x);
                break;
            case 2:
                x=extractmax(Q);
                cout<<"Max Priority element="<<x<<endl;
                break;
            case 3:
                display(Q);
                break;
            default:;
        }
    }
}
