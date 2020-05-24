#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;


int n,m,k;
int arr[301][301];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num = 0;
    long long sum = 0;
    int a,b,c,d;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>num;
            if(i==0&&j==0) arr[i][j] = num;
            else if(j==0)
            {
                arr[i][j] = arr[i-1][m-1]+num;
            }
            else
            {
                arr[i][j] = arr[i][j-1] + num;
            }
        }
    }
    cin>>k;

    for (int i = 0; i < k; ++i)
    {
        cin>>a>>b>>c>>d;
        cout<<arr[c][d]-arr[a][b]<<"\n";
    }
    cout<<sum<<"\n";
}  