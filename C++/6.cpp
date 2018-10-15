//Sudoku Solver
#include <bits/stdc++.h>

using namespace std;

#define N 9


/*
0 0 5  0 0 0  0 0 0
0 0 0  0 0 7  0 3 1
0 0 8  6 0 0  0 4 0

0 9 4  8 0 0  0 0 0
0 5 0  0 0 6  0 0 0
8 1 0  0 0 5  0 0 0

0 0 0  3 7 0  4 0 5
0 0 1  4 0 0  0 6 0
0 7 0  0 0 0  0 0 0
*/
/*
8 0 1  7 0 2  0 4 0
0 0 6  4 0 0  0 3 0
3 0 0  5 0 0  0 0 0

0 0 7  3 9 0  0 0 0
0 6 8  1 0 5  4 9 0
0 0 0  0 2 8  7 0 0

0 0 0  0 0 6  0 0 2
0 3 0  0 0 7  9 0 0
0 4 0  2 0 3  5 0 7

*/


/*
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0

*/

void print(std::vector<std::vector<int> > grid)
{
    cout<<"\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
        std::cout  << '\n';
    }
}

bool nonviolate(std::vector<std::vector<int> > grid)
{
    //cout<<"Checking violation...";
    //print(grid);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=j+1;k<N;k++)
            {
                if(grid[i][k]&&grid[i][j]==grid[i][k])
                    return false;
                if(grid[j][i]&&grid[j][i]==grid[k][i])
                    return false;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<N;k++)
            {
                for(int l=k+1;l<N;l++)
                {
                    if(grid[3*i+k/3][3*j+k%3]&&grid[3*i+k/3][3*j+k%3]==grid[3*i+l/3][3*j+l%3])
                        return false;
                }
            }
        }
    }
}

bool complete(std::vector<std::vector<int> > grid)
{
    //print(grid);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!grid[i][j])
                return false;
        }
    }
    //print(grid);
    return true;
}

std::vector<std::vector<int> > solve(std::vector<std::vector<int> > grid,int curr_i=0,int curr_j=0)
{
    std::vector<std::vector<int> > temp(N,std::vector<int> (N,0));
    if(curr_i*N+curr_j>=N*N)
    {
        return grid;
    }
    if(grid[curr_i][curr_j])
    {
        return solve(grid,curr_i+(curr_j+1)/N,(curr_j+1)%N);
    }
    for(int i=1;i<=N;i++)
    {
        grid[curr_i][curr_j]=i;
        //cout<<curr_i<<" "<<curr_j<<" "<<i<<"\n";
        if(nonviolate(grid))
        {
            //cout<<"Doesn't violate!\n\n";
            temp=solve(grid,curr_i+(curr_j+1)/N,(curr_j+1)%N);
            if(complete(temp))
            {
                //cout<<"Return from "<<curr_i<<","<<curr_j<<"\n";
                return temp;
            }
        }
        //else
            //cout<<"Violates\n\n";
        grid[curr_i][curr_j]=0;
    }
    return grid;

}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int> > grid(N,std::vector<int> (N,0));

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cin>>grid[i][j];
    }

    grid=solve(grid);
    if(!complete(grid))
    {
        cout<<"Unsolvable\n";
        return 0;
    }
    print(grid);
    return 0;
}
//
