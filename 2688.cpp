#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long arr[10][65];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n = 0;

    for (int i = 0; i < 10; ++i)
    {
        arr[i][1] = 1;
    }
    for (int i = 2; i < 66; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                arr[j][i] =  arr[j][i] + arr[k][i-1];
            }
        }
    }

    cin>>n;
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        cout<<arr[9][num+1]<<"\n";
    }
    return 0;
}