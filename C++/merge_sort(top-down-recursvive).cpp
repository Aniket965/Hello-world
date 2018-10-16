#include <bits/stdc++.h>
using namespace std;
void copies(vector <int>&v,vector<int>&temp,int low,int high)
{
    for(int i=low;i<=high;i++)
        v[i]=temp[i];
}
void merges(vector <int>&v,vector<int>&temp,int low1,int high1,int low2,int high2)
{
    int i=low1;
    int j=low2;
    int k=low1;
    while(i<=high1 && j<=high2)
    {
        if(v[i]<=v[j])
            temp[k++]=v[i++];
        else
            temp[k++]=v[j++];
    }
    while(i<=high1)
    temp[k++]=v[i++];

    while(j<=high2)
    temp[k++]=v[j++];

}
void merge_sort(vector <int>&v,int low,int high)
{
    int mid;
    vector <int> temp(v.size());
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(v,low,mid);
        merge_sort(v,mid+1,high);

        merges(v,temp,low,mid,mid+1,high);
        copies(v,temp,low,high);
    }
}
int main()
{
    vector <int> v;

    cout<<"Enter the no of elements: ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    // input ends and sorting begins.
    merge_sort(v,0,n-1);

    // sorting ends:) ...and printing begins.

    for(int i=0;i<n;i++)
        cout<<v[i]<<" " ;

    cout<<"\n";
    return 0;
}
