#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,t;
int arr[101][101];
int chk[101][101];
int mn = 10005;
int bfs()
{
    queue< pair<int,int> >q;
    q.push(make_pair(0,0));
    chk[0][0] = 1;
    while(!q.empty())
    {
        
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y==n-1&&x==m-1)
        {
            if(chk[y][x]-1<mn) mn = chk[y][x]-1;
            return 0;
        }
        if(arr[y][x]==2)
        {
            mn = chk[y][x] + (n-1-y)+(m-1-x)-1;
        }
        if(y+1<n&&arr[y+1][x]!=1&&chk[y+1][x]==0)
        {
            q.push(make_pair(y+1,x));
            chk[y+1][x] = chk[y][x] + 1;
        }
        if(y-1>=0&&arr[y-1][x]!=1&&chk[y-1][x]==0)
        {
            q.push(make_pair(y-1,x));
            chk[y-1][x] = chk[y][x] + 1;
        }
        if(x+1<m&&arr[y][x+1]!=1&&chk[y][x+1]==0)
        {
            q.push(make_pair(y,x+1));
            chk[y][x+1] = chk[y][x] + 1;
        }
        if(x-1>=0&&arr[y][x-1]!=1&&chk[y][x-1]==0)
        {
            q.push(make_pair(y,x-1));
            chk[y][x-1] = chk[y][x] + 1;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m>>t;

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    bfs();
    if(mn>t) cout<<"Fail"<<"\n";
    else cout<<mn<<"\n";
    return 0;
}  