#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int arr[51][51];
int chk[51][51];
int cnt;
int n,m,t;

int bfs(int a, int b)
{
    queue< pair<int,int> >q;
    q.push(make_pair(a,b));
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y+1<n&&chk[y+1][x]==0&&arr[y+1][x]==1)
        {
            chk[y+1][x] = cnt;
            q.push(make_pair(y+1,x));
        }
        if(y-1>=0&&chk[y-1][x]==0&&arr[y-1][x]==1)
        {
            chk[y-1][x] = cnt;
            q.push(make_pair(y-1,x));
        }
        if(x+1<m&&chk[y][x+1]==0&&arr[y][x+1]==1)
        {
            chk[y][x+1] = cnt;
            q.push(make_pair(y,x+1));
        }
        if(x-1>=0&&chk[y][x-1]==0&&arr[y][x-1]==1)
        {
            chk[y][x-1] = cnt;
            q.push(make_pair(y,x-1));
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int k,a,b;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>m>>n>>k;
        cnt = 0;
        for (int j = 0; j < k; ++j)
        {
            cin>>a>>b;
            arr[b][a] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            for (int l = 0; l < m; ++l)
            {
                if(arr[j][l]==1&&chk[j][l]==0)
                {
                    cnt++;
                    chk[j][l] = cnt;
                    bfs(j,l);
                }
            }
        }
        for (int j = 0; j < n; ++j)
        {
            for (int l = 0; l < m; ++l)
            {
                arr[j][l] = 0;
                chk[j][l] = 0;
            }
        }
        cout<<cnt<<"\n";
    }

}  