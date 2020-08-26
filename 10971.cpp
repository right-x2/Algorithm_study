#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[10][10];
int n;

int solve(int start , int pos, int visited)
{
    if(visited==(1 << n) -1)
    {
        return arr[pos][start];
    }

    int ret = 876554321;

    for (int i = 0; i < n; ++i)
    {
        if(!(visited&(1 << i)) && arr[pos][i])
        {
            int tmp = arr[pos][i] + solve(start,i,visited|(1 << i));
            if(tmp<ret) ret = tmp;
        }
    }

    return ret;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0) arr[i][j] = 876554321;
        }
    }

    int ans = 876554321;
    for (int i = 0; i < n; ++i)
    {
        int temp = solve(i,i,1 << i);
        if(ans>temp) ans = temp;
    }

    cout<<ans<<"\n";
    return 0;
}