#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[51][51];
int chk[51][51];
int n,m,y,x,way;
int cnt = 1;
int solve()
{
    int temp;
    chk[y][x] = cnt;
    for (int i = 1; i <= 4; ++i)
    {
        if(way-i<0) temp = way-i+4;
        else temp = way - i;
        if(temp==0&&y-1>=0&&arr[y-1][x]==0&&chk[y-1][x]==0)
        {
            y--;
            cnt++;
            way = temp;
            solve();
            return 0;
        }
        else if(temp==1&&x+1<m&&arr[y][x+1]==0&&chk[y][x+1]==0)
        {
            x++;
            cnt++;
            way = temp;
            solve();
            return 0;
        }
        else if(temp==2&&y+1<n&&arr[y+1][x]==0&&chk[y+1][x]==0)
        {
            y++;
            cnt++;
            way = temp;
            solve();
            return 0;
        }
        else if(temp==3&&x-1>=0&&arr[y][x-1]==0&&chk[y][x-1]==0)
        {
            x--;
            cnt++;
            way = temp;
            solve();
            return 0;
        }
    }
    if(way==0)
    {
        if(y+1<n&&arr[y+1][x]==0)
        {
            y++;
            solve();
        }
        else
        {
            return 0;
        }
    }
    else if(way==1)
    {
        if(x-1>=0&&arr[y][x-1]==0)
        {
            x--;
            solve();
        }
        else
        {
            return 0;
        }
    }
    else if(way==2)
    {
        if(y-1>=0&&arr[y-1][x]==0)
        {
            y--;
            solve();
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(x+1<m&&arr[y][x+1]==0)
        {
            x++;
            solve();
        }
        else
        {
            return 0;
        }
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    cin>>y>>x>>way;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
        }
    }
    solve();
    cout<<cnt<<"\n";
    return 0;
}