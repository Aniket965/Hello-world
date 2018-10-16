/*
DYNAMIC PROGRAMMING

The program finds the longest common subsequence between two strings,
i.e. given two strings the program will find the longest common subsequence
between them.

eg. abcdaf(string 1)
    acbcf (string 2)

    lcs - abcf

Wiki - https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char arr[100], arr1[100];
    cout<<"\nEnter the first string: ";
    cin>>arr;
    cout<<"\nEnter the second string: ";
    cin>>arr1;
    int len_first,len_second;
    len_first = strlen(arr);
    len_second = strlen(arr1);
    int final_matrix[len_second + 1][len_first + 1];
    int i=0,j=0;
    for(i=0;i<=len_second;i++)
    {
        final_matrix[i][0] = 0;
    }
    for(i=0;i<=len_first;i++)
    {
        final_matrix[0][i] = 0;
    }
    for(i=1;i<=len_second; i++)
    {
        for(j=1;j<=len_first;j++)
        {
            if(arr1[i-1] == arr[j-1])
            {
                //cout<<"\nValue match is(i:j:val): "<<i<<":"<<j<<":"<<final_matrix[i - 1][j - 1] + 1;
                final_matrix[i][j] = final_matrix[i - 1][j - 1] + 1;
            }
            else
            {
                //cout<<"\nValue  not match is(i:j:val): "<<i<<":"<<j<<":"<<max(final_matrix[i - 1][j], final_matrix[i][j - 1]);
                final_matrix[i][j] = max(final_matrix[i - 1][j], final_matrix[i][j - 1]);
            }
        }
    }
    cout<<"\nThe longest common subsequence is of length: "<<final_matrix[len_second][len_first]<<endl;;
    return 0;
}