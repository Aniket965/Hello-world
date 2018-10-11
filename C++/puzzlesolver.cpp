#include <bits/stdc++.h>
using namespace std;
#ifndef N
#define N 3
#endif
#define grid std::vector<std::vector<int> >

void print(grid A,ostream &fout=cout) {
    int n = A.size();
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            fout << A[i][j] << " ";
        }
        fout << "\n";
    }
    fout << "\n";
}

void print(std::vector<pair<grid  , long > > A) {
    int n = A.size();
    for (int in=0; in<n; in++)
    {
        for (int i=0; i<N; i++)
        {
            for(int j=0;j<N;j++)
                cout << A[in].first[i][j] << " ";
            cout<<"\n";
        }
        cout <<A[in].second<< "\n";

    }
    cout << "\n";
}

long find(std::vector< pair< grid  , long > > A,grid key)
{
    long i=0;
    for(std::vector< pair< grid  , long > >::iterator iter=A.begin();iter!=A.end();iter++)
    {
        if((*iter).first==key)
            return i;
        i++;
    }
    return -1;
}

void whereis(grid A,int &ti,int &tj)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(A[i][j]==-1)
            {
                ti=i;
                tj=j;
                return ;
            }
        }
    }
    return ;
}

std::vector< pair< grid  , long > > visited;

long Solve(grid initmat,grid finalmat,long curr,ostream &fout=cout)
{
    if(curr==(int)(visited.end()-visited.begin()))
        return -1;

    int ti=-1,tj=-1;

    initmat=visited[curr].first;
    long cost=visited[curr].second;
    whereis(initmat,ti,tj);
    if(ti==-1||tj==-1)
        return Solve(initmat,finalmat,++curr,fout);
    if(ti>=N||tj>=N||ti<0||tj<0)
        return Solve(initmat,finalmat,++curr,fout);

    int flag=0;
    long ret=INT_MAX;


    if(ti<N-1)
    {
        initmat[ti][tj]=initmat[ti+1][tj];
        initmat[ti+1][tj]=-1;

        int found=find(visited,initmat);
        if(found>=0)
        {
            if(visited[found].second>cost+1)
                visited[found].second=cost+1;
        }
        else
        {
            visited.push_back(make_pair(initmat,cost+1));
            flag=1;
        }

        initmat[ti+1][tj]=initmat[ti][tj];
        initmat[ti][tj]=-1;
    }
    if(tj<N-1)
    {
        initmat[ti][tj]=initmat[ti][tj+1];
        initmat[ti][tj+1]=-1;


        int found=find(visited,initmat);
        if(found>=0)
        {
            if(visited[found].second>cost+1)
                visited[found].second=cost+1;
        }
        else
        {
            visited.push_back(make_pair(initmat,cost+1));
            flag=1;
        }

        initmat[ti][tj+1]=initmat[ti][tj];
        initmat[ti][tj]=-1;
    }

    if(ti>0)
    {
        initmat[ti][tj]=initmat[ti-1][tj];
        initmat[ti-1][tj]=-1;

        int found=find(visited,initmat);
        if(found>=0)
        {
            if(visited[found].second>cost+1)
                visited[found].second=cost+1;
        }
        else
        {

            visited.push_back(make_pair(initmat,cost+1));

            flag=1;
        }

        initmat[ti-1][tj]=initmat[ti][tj];
        initmat[ti][tj]=-1;
    }
    if(tj>0)
    {
        initmat[ti][tj]=initmat[ti][tj-1];
        initmat[ti][tj-1]=-1;


        int found=find(visited,initmat);
        if(found>=0)
        {
            if(visited[found].second>cost+1)
                visited[found].second=cost+1;
        }
        else
        {
            visited.push_back(make_pair(initmat,cost+1));
            flag=1;
        }

        initmat[ti][tj-1]=initmat[ti][tj];
        initmat[ti][tj]=-1;
    }
    curr=curr+1;
    Solve(initmat,finalmat,curr,fout);
    return 0;
}

int main()
{
    grid initmat(N,std::vector<int> (N)),finalmat(N,std::vector<int> (N));
    int ti=-1,tj=-1;
    cout<<"Enter initial Matrix:\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int x;
            cin>>x;
            initmat[i][j]=x;
            if(x==-1)
            {
                if(ti!=-1||tj!=-1)
                {
                    cout<<"Error!\n";
                    return 0;
                }
                ti=i;
                tj=j;
            }
        }
    }
    if(ti==-1||tj==-1)
    {
        cout<<"Error!\n";
        return 0;
    }


    cout<<"Enter final Matrix:\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cin>>finalmat[i][j];
    }

    ofstream fout("file_puzzle.txt",ios::out);
    bool Sol=0;
    visited.push_back(make_pair(initmat,0));
    Solve(initmat,finalmat,0);
    cout<<"Min moves:"<<visited[find(visited,finalmat)].second<<"\n";
    fout.close();
    //print(visited);

}
