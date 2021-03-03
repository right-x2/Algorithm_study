#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];
int chk[1001][1001];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int idx[1000001];
int temp[1000001];
int n,m;
int cnt = 0;

void bfs(int a, int b)
{
    queue<pair<int,int> >q;

    q.push(make_pair(a,b));
    chk[a][b] = cnt;
    int alcnt = 0;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        alcnt++;
        for(int i = 0; i < 4; i++)
        {
            if(y+dy[i]>=0&&y+dy[i]<n&&x+dx[i]>=0&&x+dx[i]<m&&arr[dy[i]+y][dx[i]+x]==0&&chk[dy[i]+y][dx[i]+x]==0)
            {
                chk[dy[i]+y][dx[i]+x] = cnt;
                q.push(make_pair(dy[i]+y,dx[i]+x));
            }
        }
    }
    idx[cnt] = alcnt;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    cin>>n>>m;

    for(int i = 0; i < n; i++)
    {
        cin>>str;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = str[j]-'0';
        }
    }

    for(int i =0; i< n; i++)
    {
        for(int j =0;j<m;j++)
        {
            if(arr[i][j]==0&&chk[i][j]==0)
            {
                cnt++;
                bfs(i,j);
            }
        }
    }
    int tmp = 0;
    for(int i =0; i< n; i++)
    {
        for(int j =0;j<m ;j++)
        {
            if(arr[i][j]==0) continue;
            tmp++;
            int sum = 1;
            for (int k = 0; k < 4; k++)
            {
                if(i+dy[k]>=0&&i+dy[k]<n&&j+dx[k]>=0&&j+dx[k]<m&&temp[chk[i+dy[k]][j+dx[k]]]!=tmp)
                {
                    temp[chk[i+dy[k]][j+dx[k]]]=tmp;
                    sum = sum + idx[chk[i+dy[k]][j+dx[k]]];
                }
            }
            arr[i][j] = sum%10;
        }
    }


    for(int i =0; i<n; i++)
    {
        for(int j= 0; j<m; j++)
        {
            cout<<arr[i][j]<<"";
        }
        cout<<"\n";
    }
    
    return 0;
}