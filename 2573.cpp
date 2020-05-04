#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


int mn;
int n,m;
int cnt;
int arr[301][301];
int chk[301][301];
queue< pair<int,int> >q;

int bfs(int i, int j)
{
    stack< pair<int,int> > box;
    box.push(make_pair(i,j));
    while(!box.empty())
    {
        int y = box.top().first;
        int x = box.top().second;
        box.pop();
        chk[y][x] = 1;
        if(y+1<n&&chk[y+1][x]==0&&arr[y+1][x]!=0) box.push(make_pair(y+1,x));
        if(y-1>=0&&chk[y-1][x]==0&&arr[y-1][x]!=0) box.push(make_pair(y-1,x));
        if(x+1<m&&chk[y][x+1]==0&&arr[y][x+1]!=0) box.push(make_pair(y,x+1));
        if(x-1>=0&&chk[y][x-1]==0&&arr[y][x-1]!=0) box.push(make_pair(y,x-1));
    }
    return 0;
}

int solve()
{
    int count = 0;
    int tt = 0;
    int answer = 0;
    while(!q.empty())
    {
        if(count==cnt)
        {
            int ans = 0;
            answer++;
            for (int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; j++)
                {
                    if(arr[i][j]==-1) arr[i][j]=0;
                }
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(arr[i][j]!=0&&chk[i][j]==0) 
                    {
                        if(ans==1)
                        {
                            mn = answer;
                            return 0;
                        }
                        ans++;
                        bfs(i,j);
                    }
                }
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    chk[i][j] = 0;
                }
            }
            cnt = tt;
            count = 0;
            tt = 0;
        }
        else
        {
            int num = 0;
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if(y-1>=0&&arr[y-1][x]==0) num++;
            if(y+1<n&&arr[y+1][x]==0) num++;
            if(x-1>=0&&arr[y][x-1]==0) num++;
            if(x+1<m&&arr[y][x+1]==0) num++;

            if(arr[y][x]<=num) arr[y][x] = -1;
            else 
            {
                arr[y][x] = arr[y][x]-num;
                q.push(make_pair(y,x));
                tt++;
            }
            count++;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n>>m;;

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=0)
            {
                q.push(make_pair(i,j));
                cnt++;
            }
        }
    }
    solve();
    cout<<mn<<"\n";
    return 0;
}