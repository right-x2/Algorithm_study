#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char arr[101][101];
int visited[101][101];
int w,ans;
int n,m;
queue< pair<int,int> >q;

int bfs(int a, int b)
{
    
    int cnt = 1;
    q.push(make_pair(a,b));
    char k = arr[a][b];
    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();        
        if(y+1<n&&arr[y+1][x]==k&&visited[y+1][x]==0)
        {
            q.push(make_pair(y+1,x));
            visited[y+1][x] = 1;
            cnt++;
        }

        if(y-1>=0&&arr[y-1][x]==k&&visited[y-1][x]==0)
        {
            q.push(make_pair(y-1,x));
            visited[y-1][x] = 1;
            cnt++;
        }

        if(x+1<m&&arr[y][x+1]==k&&visited[y][x+1]==0)
        {
            q.push(make_pair(y,x+1));
            visited[y][x+1] = 1;
            cnt++;
        }

        if(x-1>=0&&arr[y][x-1]==k&&visited[y][x-1]==0)
        {
            q.push(make_pair(y,x-1));
            visited[y][x-1] = 1;
            cnt++;
        }
    }
    if(k=='W') w = w + cnt*cnt;
    else ans = ans + cnt*cnt;

    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>m>>n;
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(visited[i][j]==0) 
            {
                visited[i][j] = 1;
                bfs(i,j);
            }
        }
    }

    cout<<w<<" "<<ans<<"\n";
    return 0;
}  