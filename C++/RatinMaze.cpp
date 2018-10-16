#include<iostream>
#include<stdlib.h>
#define m 5
#define n 4
using namespace std;
void RatinMaze_Count(char(*)[n], char(*)[n] , int , int); /// <== DECLARATION.
int main()
{
    char B[m][n]= {{'O','O','O','O'},
                   {'O','X','O','X'},
                   {'O','X','O','O'},
                   {'O','O','X','O'},
                   {'O','O','O','O'}
                   };
    char aB[m][n]= {{'O','O','O','O'},
                    {'O','X','O','X'},
                    {'O','X','O','O'},
                    {'O','O','X','O'},
                    {'O','O','O','O'}
                    };
    aB[0][0]='1';
    RatinMaze_Count(B,aB,0,0);
}
void RatinMaze_Count(char B[m][n], char aB[m][n], int r, int c)
{
    if(r==m-1&&c==n-1)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) cout<<aB[i][j];
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    /// moving right
    if(c+1<n&&B[r][c+1]!='X')
    {
        aB[r][c+1]='1';
        RatinMaze_Count(B,aB,r,c+1);
        aB[r][c+1]=B[r][c+1];
    }
    /// moving down
    if(r+1<m&&B[r+1][c]!='X')
    {
        aB[r+1][c]='1';
        RatinMaze_Count(B,aB,r+1,c);
        aB[r+1][c]=B[r+1][c];
    }
    return;
}
///  TO RETURN THE NUMBER OF WAYS, IT CAN WIN.
///#include <iostream>
///using namespace std;
///#define m 5
///#define n 4
///
///int RatinMaze_Count(char Board[m][n],int rRow, int rCol){
///    static int cnt=0;
///    if (rRow==m-1 && rCol==n-1){
///        cnt++;
///        return cnt;
///    }
///    ///lets move right
///    if (rCol+1<n && Board[rRow][rCol+1]!='h'){
///        RatinMaze_Count(Board,rRow, rCol+1);
///    }
///    ///let move down
///    if (rRow+1<m && Board[rRow+1][rCol]!='h'){
///        RatinMaze_Count(Board,rRow+1,rCol);
///    }
///    return cnt;/// this return is for returning final cnt to main();
///}
///
///int main(){
///    char Board[m][n]={ {'n','n','n','n'},
///                       {'n','h','n','h'},
///                       {'n','h','n','n'},
///                       {'n','h','h','n'},
///                       {'n','n','n','n'}};
///    int cnt=RatinMaze_Count(Board,0,0);
///    cout<<cnt;
///
///
///}
