#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char arr[101][101];
int ck[101][101];
int n;
int alcnt;

int dfs(int i, int j)
{
    ck[i][j] = 1;

    if(i+1<n)
    {
        if(arr[i][j]==arr[i+1][j]&&ck[i+1][j] == 0)
        {
            dfs(i+1,j);
        }
    }

    if(j+1<n)
    {
        if(arr[i][j]==arr[i][j+1]&&ck[i][j+1] == 0)
        {
            dfs(i,j+1);
        }
    }

    if(i-1>=0)
    {
        if(arr[i][j]==arr[i-1][j]&&ck[i-1][j] == 0)
        {
            dfs(i-1,j);
        }
    }

    if(j-1>=0)
    {
        if(arr[i][j]==arr[i][j-1]&&ck[i][j-1] == 0)
        {
            dfs(i,j-1);
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int fst;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(ck[i][j]==0)
            {
                dfs(i,j);
                alcnt++;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(arr[i][j]=='R') arr[i][j]='G';
            ck[i][j] = 0;
        }
    }
    fst = alcnt;
    alcnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(ck[i][j]==0)
            {
                dfs(i,j);
                alcnt++;
            }
        }
    }
    cout<<fst<<" "<<alcnt<<"\n";
}  