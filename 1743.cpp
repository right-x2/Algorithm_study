#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[101][101];
int visited[101][101];
int n,m;
queue< pair<int,int> >q;
int mx = 0;
int bfs(int a, int b)
{
    
    int cnt = 1;
    q.push(make_pair(a,b));
    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();        
        if(y+1<=n&&arr[y+1][x]==1&&visited[y+1][x]==0)
        {
            q.push(make_pair(y+1,x));
            visited[y+1][x] = 1;
            cnt++;
        }

        if(y-1>=0&&arr[y-1][x]==1&&visited[y-1][x]==0)
        {
            q.push(make_pair(y-1,x));
            visited[y-1][x] = 1;
            cnt++;
        }

        if(x+1<=m&&arr[y][x+1]==1&&visited[y][x+1]==0)
        {
            q.push(make_pair(y,x+1));
            visited[y][x+1] = 1;
            cnt++;
        }

        if(x-1>=0&&arr[y][x-1]==1&&visited[y][x-1]==0)
        {
            q.push(make_pair(y,x-1));
            visited[y][x-1] = 1;
            cnt++;
        }
    }
    if(mx<cnt) mx = cnt;
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,t;
    cin>>n>>m>>t;
    for(int i = 0; i < t ; i++)
    {
        cin>>a>>b;
        arr[a][b] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if(visited[i][j]==0&&arr[i][j]==1) 
            {
                visited[i][j] = 1;
                bfs(i,j);
            }
        }
    }
    cout<<mx<<"\n";
    return 0;
}  