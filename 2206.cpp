#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char arr[1001][1001];
int chk[1001][1001];
int n,m;
int mn = 1000000;

queue< pair<int , int> > q;

int dfs(int i, int j, int cnt)
{
    if(cnt>mn) return 0;
    if(i==n&&j==m)
    {
        if(cnt<mn) mn = cnt;
        return 0;
    }
    if(i>1&&i<n)
    {
        if(chk[i-1][j]==0&&arr[i-1][j]=='0')
        {
            chk[i-1][j] = 1;
            dfs(i-1,j,cnt+1);
            chk[i-1][j] = 0;
        }
        if(chk[i+1][j]==0&&arr[i+1][j]=='0')
        {
            chk[i+1][j] = 1;
            dfs(i+1,j,cnt+1);
            chk[i+1][j] = 0;
        }
    }
    else if(i==1)
    {
        if(chk[i+1][j]==0&&arr[i+1][j]=='0')
        {
            chk[i+1][j] = 1;
            dfs(i+1,j,cnt+1);
            chk[i+1][j] = 0;
        }
    }
    else if(i==n)
    {
        if(chk[i-1][j]==0&&arr[i-1][j]=='0')
        {
            chk[i-1][j] = 1;
            dfs(i-1,j,cnt+1);
            chk[i-1][j] = 0;
        }    
    }

    if(j>1&&j<m)
    {
        if(chk[i][j+1]==0&&arr[i][j+1]=='0')
        {

            chk[i][j+1] = 1;
            dfs(i,j+1,cnt+1);
            chk[i][j+1] = 0;
        }
        if(chk[i][j-1]==0&&arr[i][j-1]=='0')
        {
            chk[i][j-1] = 1;
            dfs(i,j-1,cnt+1);
            chk[i][j-1] = 0;
        }
    }

    else if(j==1)
    {
        if(chk[i][j+1]==0&&arr[i][j+1]=='0')
        {
            chk[i][j+1] = 1;
            dfs(i,j+1,cnt+1);
            chk[i][j+1] = 0;
        }
    }
    else if(j==m)
    {
        if(chk[i][j-1]==0&&arr[i][j-1]=='0')
        {
            chk[i][j-1] = 1;
            dfs(i,j-1,cnt+1);
            chk[i][j-1] = 0;
        }        
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string tmp;
    int qsz = 0;
    cin>>n>>m;
    for (int i = 1; i<= n; ++i)
    {
        cin>>tmp;
        for (int j = 1; j<= m; ++j)
        {
            if(tmp[j-1]=='1')
            {
                q.push(make_pair(i,j));
                qsz++;
            }
            arr[i][j] = tmp[j-1];
        }
    }
    for (int i = 0; i < qsz; ++i)
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        arr[y][x] = '0';
        dfs(1,1,1);
        arr[y][x] = '1';
    }
    if(mn==1000000) cout<<-1<<"\n";
    else cout<<mn<<"\n";
}  