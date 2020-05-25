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
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin>>num;
            if(i==1) arr[i][j] = num;
            else
            {
                arr[i][j] = arr[i-1][j]+num;
            }
        }
    }
    cin>>k;

    for (int i = 0; i < k; ++i)
    {
        cin>>a>>b>>c>>d;
        long long sum = 0;
        for (int j = b; j <=d ; ++j)
        {
            sum = sum + arr[c][j]-arr[a-1][j];
        }
        cout<<sum<<"\n";
    }
}  