#include <stdio.h>
#include <stdlib.h>

struct spice
{
	float profit;
	int weight;
	float x;
};


struct spice *items;


// A binary search based function to find the position
// where item should be inserted in a[low..high]
int binarySearch(struct spice a[], struct spice item, int low, int high)
{
    if (high <= low)
        return ((item.profit/item.weight) < (a[low].profit/a[low].weight))?  (low + 1): low;
 
    int mid = (low + high)/2;
 
    if((item.profit/item.weight) == (a[mid].profit/a[mid].weight))
        return mid+1;
 
    if((item.profit/item.weight) < (a[mid].profit/a[mid].weight))
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
 
// Function to sort an array a[] of size \'n\'
void sort(struct spice a[], int n)
{
    int i, loc, j, k;

    struct spice selected;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
 
        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}


float MAX_PROFIT(int n,int c)
{
	int i,w;
	float p;
	i=0;
	p=0;		//total profit of included items 
	w=0;		//total weight of included items

	//it will run as long as weight included in bag is less than capacity
	while(w<c)
	{
		//if weight is still less than capacity after including i'th spice
		if(w+items[i].weight<c)
		{
			items[i].x=1;
			w=w+items[i].weight;
		}
		//if weight is greater than capacity after including i'th spice
		else
		{
			items[i].x=((float)(c-w))/((float)items[i].weight);	//fill the remaining space with fraction of i'th spice 
			w=c;
		}
		p=p+(items[i].profit*items[i].x);	//updating profit of spices included in bag
		i++;		
	}
	return p;
}


int main()
{
	int n,i,c;


	printf("Enter No. of spices in Store:");
	scanf("%d",&n);


	items=(struct spice *)malloc(n*sizeof(struct spice));

	printf("Enter Spice Information:\n");
	for (i = 0; i < n; ++i)
	{
		scanf("%f %d",&items[i].profit,&items[i].weight);
		items[i].x=0;
	}

 	sort(items,n);


 	printf("Enter capacity of bag:");
 	scanf("%d",&c);

 	printf("Maximum profit: %f\n",MAX_PROFIT(n,c));

 	for (i = 0; i < n; ++i)
 	{
 		printf("%.2f %d %.2f %.2f\n",items[i].profit,items[i].weight,items[i].x,items[i].profit/items[i].weight);
 	}


 	return 0;
}
