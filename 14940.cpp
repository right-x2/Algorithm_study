#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m;
int arr[1001][1001];
int chk[1001][1001];
int a,b;


void bfs()
{
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    while (!q.empty())
    {
        
        int y = q.front().first;
        int x = q.front().second;
        int cnt = chk[y][x];
        q.pop();
        cout<<y<<" "<<x<<"\n";
        for (int i = 0; i < 4; i++)
        {
            if(dy[i]+y>=0&&dy[i]+y<n&&dx[i]+x>=0&&dx[i]+x<m&&chk[dy[i]+y][dx[i]+x]==-1)
            {
                chk[dy[i]+y][dx[i]+x]=cnt+1;
                q.push(make_pair(dy[i]+y,dx[i]+x));
            }
        }
        
    }
    
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)chk[i][j]=-1;
            if(arr[i][j]==2)
            {
                a = i;
                b = j;
            }
        }
    }
    bfs();
    
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<chk[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}