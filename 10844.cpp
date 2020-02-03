#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][11];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    long long sum = 0;
    for (int i = 1; i <= 9; ++i)
    {
        arr[0][i] = 1;
    }
    cin>>a;
    for (int i = 1; i <a; i++)
    {
        for (int j = 0; j <= 9; ++j)
        {
            if(j==0)
            {
                arr[i][j] = arr[i-1][1]%1000000000;
            }
            else if(j==9)
            {
                arr[i][j] = arr[i-1][8]%1000000000;
            }
            else
            {
                arr[i][j] = arr[i-1][j-1]%1000000000 + arr[i-1][j+1]%1000000000;
            }
        }
    }
    for (int i = 0; i <= 9; ++i)
    {
        sum = sum + arr[a-1][i];
    }
    sum = sum%1000000000;
    cout<<sum<<"\n";
}  