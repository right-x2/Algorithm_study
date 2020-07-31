#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,-1,-1,-1,0,1,1,1};
queue<pair<int,int> >pq;
int arr[51][51];
int tmp[51][51];
int ans=0;
int n,m;
int bfs(int a, int b)
{
    queue<pair<int,pair<int,int> > >q;

    q.push(make_pair(1,make_pair(a,b)));
    while(!q.empty())
    {
        int cnt = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            if(y+dy[i]>=0&&y+dy[i]<n&&x+dx[i]<m&&x+dx[i]>=0)
            {
                if(arr[y+dy[i]][x+dx[i]]==1)
                {
                    if(ans<cnt) ans = cnt;
                    return 0;
                }
                else if(arr[y+dy[i]][x+dx[i]]==0)
                {
                    arr[y+dy[i]][x+dx[i]] = -1;
                    q.push(make_pair(cnt+1,make_pair(y+dy[i],x+dx[i])));
                } 
            }
        }
    }
    return 0; 
}

int solve()
{
    while(!pq.empty())
    {
        int y = pq.front().first;
        int x = pq.front().second;
        pq.pop();
        bfs(y,x);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                arr[i][j] = tmp[i][j];
            }
        }
    }
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    

    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
            if(arr[i][j]==0) pq.push(make_pair(i,j));
        }
    }
    solve();
    cout<<ans<<"\n";
    return 0;
}