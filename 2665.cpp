#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int arr[51][51];
int chk[51][51][51];
int ans = -1;

int dp[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
struct P
{
    int y;
    int x;
    int cnt;
};

struct cmp {
    bool operator()(const P &u, const P &v) {
        return u.cnt > v.cnt;
    }
};


int bfs()
{
    priority_queue<P,vector<P>,cmp >q;
    P p;
    p.y = 0;
    p.x = 0;
    p.cnt = 0;
    q.push(p);
    while(!q.empty())
    {
        int y = q.top().y;
        int x = q.top().x;
        int cnt = q.top().cnt;
        q.pop();
        if(y==n-1&&x==n-1)
        {
            ans = cnt;
            return 0;
        }

        for (int i = 0; i < 4; ++i)
        {
            if(y+dp[i][0]>=0&&y+dp[i][0]<n&&x+dp[i][1]>=0&&x+dp[i][1]<n)
            {
                if(arr[y+dp[i][0]][x+dp[i][1]]==0&&chk[y+dp[i][0]][x+dp[i][1]][cnt+1]==0)
                {
                    chk[y+dp[i][0]][x+dp[i][1]][cnt+1] = 1;
                    P tmp;
                    tmp.y = y+dp[i][0];
                    tmp.x = x+dp[i][1];
                    tmp.cnt = cnt+1;
                    q.push(tmp);
                }
                else if(arr[y+dp[i][0]][x+dp[i][1]]==1&&chk[y+dp[i][0]][x+dp[i][1]][cnt]==0)
                {
                    chk[y+dp[i][0]][x+dp[i][1]][cnt] = 1;
                    P tmp;
                    tmp.y = y+dp[i][0];
                    tmp.x = x+dp[i][1];
                    tmp.cnt = cnt;
                    q.push(tmp);
                }
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
    string str;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < n; ++j)
        {
            arr[i][j] = str[j]-'0';
        }
    }
    bfs();
    cout<<ans<<"";
    return 0;
}