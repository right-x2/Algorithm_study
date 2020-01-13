#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector< pair<int,int> >v;
queue< pair<int,int> > q;
int arr[1001][1001];
int n,m;
int bfs(int i, int j,int cnt)
{
    if(i+1<n)
    {
        if(arr[i+1][j]==0)
        {
            q.push(make_pair(i+1,j));
            arr[i+1][j] = cnt+1;
        }
    }
    if(i-1>=0)
    {
        if(arr[i-1][j]==0)
        {
            q.push(make_pair(i-1,j));
            arr[i-1][j] = cnt+1;
        }
    }
    if(j+1<m)
    {
        if(arr[i][j+1]==0)
        {
            q.push(make_pair(i,j+1));
            arr[i][j+1] = cnt+1;
        }
    }
    if(j-1>=0)
    {
        if(arr[i][j-1]==0)
        {
            q.push(make_pair(i,j-1));
            arr[i][j-1] = cnt+1;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int flag = 0;
    int max = 0;
    int zcnt = 0;
    int start = 0;
    int tt = 0;
    int cnt = 1;
    cin>>m>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]==0)zcnt++;
            else if(arr[i][j]==1)
            {
                q.push(make_pair(i,j));
            }
        }
    }
    if(zcnt==0) 
    {
        flag = 0;
    }
    while(!q.empty() ==1)
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(arr[i][j]==cnt) bfs(i,j,cnt);
        else if(arr[i][j]>cnt)
        {
            cnt++;
            bfs(i,j,cnt);
        }
        

    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(arr[i][j] ==0) flag = 1;
        }
    }
    if(flag==1) cout<<-1<<"\n";
    else cout<<cnt-1<<"\n";
}  