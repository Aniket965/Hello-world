#include<iostream>
using namespace std;

int parent(int i)
{i=(i%2==0)?i:i+1; 
 return ((i/2)-1);}

void swap(int *b,int *c)
{int temp=*b;
 *b=*c;
 *c=temp;
}

int is_empty(int heap_size)   //IS EMPTY
{int i=(heap_size==0)?1:0;}

void insert(int a[],int heap_size,int heap_capacity,int key)
{if(heap_size==heap_capacity)
 {cout<<"overflow";return;}
  
 int k=heap_size;
 a[k]=key;
 while(k!=0 && a[parent(k)]>a[k])
 {swap(&a[parent(k)],&a[k]);
  k=parent(k);
 }
}
void heepify(int a[],int index,int heap_size)
{
 if(is_empty(heap_size)){cout<<"heap empty";return;}
 int left=2*index+1;
 int right=2*index+2;
 int smallest=index;
 if (left<heap_size && a[left]<a[index])
		{smallest = left;}
 if (right<heap_size && a[right]<a[smallest])
		{smallest = right;}

 if(smallest!=index)
 {swap(&a[smallest],&a[index]);
  heepify(a,smallest,heap_size);
 }
}

void extract_min(int a[],int *p)
{if(is_empty(*p)){cout<<"underflow";return;}
 if(*p==1){--*p;cout<<a[0];return;}
 cout<<a[0];
 a[0]=a[*p-1];
 --*p;
 heepify(a,0,*p);
 return;
}

int main()
{int heap_capacity=100;
 int a[heap_capacity],heap_size=0; 
 
 //INSERT
 int key,number;
 cout<<"Enter no of element to insert";cin>>number;
 while(number--) 
 {cout<<"Enter element to insert";
  cin>>key;
  insert(a,heap_size,heap_capacity,key);
  heap_size++;
 }
 //cout<<"heap is"<<endl;
 for(int i=0;i<heap_size;i++){cout<<a[i]<<" ";}

 //EXTRACT MIN
 
 //extract_min(a,&heap_size);

 return 0;
}
