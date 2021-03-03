#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int arr[101][11];
int n;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;
    for (int i = 1; i < 10; i++)
    {
        arr[0][i] = 1;
    }
    for (int i = 1; i < n ;i++)
    {
        arr[i][0] = arr[i-1][1];
        for(int j = 1; j<9;j++)
        {
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%1000000000;
        }
        arr[i][9] = arr[i-1][8];
    }
    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        sum = (sum + arr[n-1][i])%1000000000;
    }
    cout<<sum<<"\n";
    
    return 0;
}