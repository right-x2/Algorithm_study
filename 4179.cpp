#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


char arr[1002][1002];
int n,m;
int fcnt;
int cnt;
int ans;
int alcnt;
queue< pair<int,int> >q;
queue< pair<int,int> >fire;
int bfs() 
{
    while(!q.empty())
    {
        alcnt++;
        int k = cnt;
        cnt = 0;

        int f = fcnt;
        fcnt = 0;


        for(int i = 0; i < k; i++)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if(arr[y][x]=='F')  continue;
            if(y==0||x==0||y==n-1||x==m-1)
            {
                ans = alcnt;
                return 0;
            } 
            if(y+1<n&&arr[y+1][x]=='.')
            {
                arr[y+1][x]='J';
                cnt++;
                q.push(make_pair(y+1,x));
            }
            if(y-1>=0&&arr[y-1][x]=='.')
            {
                arr[y-1][x]='J';
                cnt++;
                q.push(make_pair(y-1,x));
            }
            if(x+1<m&&arr[y][x+1]=='.')
            {
                arr[y][x+1]='J';
                cnt++;
                q.push(make_pair(y,x+1));
            }
            if(x-1>=0&&arr[y][x-1]=='.')
            {
                arr[y][x-1]='J';
                cnt++;
                q.push(make_pair(y,x-1));
            }
        }

        for (int i = 0; i < f; ++i)
        {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();

            if(y+1<n&&(arr[y+1][x]=='.'||arr[y+1][x]=='J'))
            {
                arr[y+1][x] = 'F';
                fcnt++;
                fire.push(make_pair(y+1,x));
            }
            if(y-1>=0&&(arr[y-1][x]=='.'||arr[y-1][x]=='J'))
            {
                arr[y-1][x] = 'F';
                fcnt++;
                fire.push(make_pair(y-1,x));
            }
            if(x+1<m&&(arr[y][x+1]=='.'||arr[y][x+1]=='J'))
            {
                arr[y][x+1] = 'F';
                fcnt++;
                fire.push(make_pair(y,x+1));
            }
            if(x-1>=0&&(arr[y][x-1]=='.'||arr[y][x-1]=='J'))
            {
                arr[y][x-1] = 'F';
                fcnt++;
                fire.push(make_pair(y,x-1));
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
    int t;
    string str;
    cin>>n>>m;
    for (int j = 0; j < n; ++j)
    {
        cin>>str;
        for (int k = 0; k < m; ++k)
        {
            arr[j][k] = str[k];
            if(arr[j][k]=='J')
            {
                q.push(make_pair(j,k));
                cnt++;
            }
            else if(arr[j][k]=='F')
            {
                fire.push(make_pair(j,k));
                fcnt++;
            }
        }
    }
    bfs();
    if(ans==0)cout<<"IMPOSSIBLE"<<"\n";
    else cout<<ans<<"\n";
    return 0;
}   