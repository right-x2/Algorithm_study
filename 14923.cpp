#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
public:
    int y;
    int x;
    int flag;
    int cnt;

    Point(int y, int x, int flag, int cnt)
    {
        this->y = y;
        this->x = x;
        this->flag = flag;
        this->cnt = cnt;
    }
};

struct cmp{
    bool operator()(Point &a, Point &b){
        return a.cnt>b.cnt;
    }
};

int a,b,c,d,n,m;
int arr[1001][1001];
int chk[2][1001][1001];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int bfs()
{
    priority_queue<Point,vector<Point>,cmp >pq;
    pq.push(Point(a,b,0,0));

    while(!pq.empty())
    {
        int y = pq.top().y;
        int x = pq.top().x;
        int flag = pq.top().flag;
        int cnt = pq.top().cnt;
        pq.pop();
        
        if(chk[flag][y][x]==1) continue;
        if(y==c&&x==d) return cnt;
        chk[flag][y][x]=1;

        for(int i = 0; i<4; i++)
        {
            if(dy[i]+y>0&&dy[i]+y<=n&&dx[i]+x>0&&dx[i]+x<=m)
            {
                if(arr[dy[i]+y][dx[i]+x]==0&&chk[flag][dy[i]+y][dx[i]+x]==0)
                {
                    pq.push(Point(dy[i]+y,dx[i]+x,flag,cnt+1));
                }
                else if(arr[dy[i]+y][dx[i]+x]==1&&chk[1][dy[i]+y][dx[i]+x]==0&&flag==0)
                {
                    pq.push(Point(dy[i]+y,dx[i]+x,1,cnt+1));
                }
            }
        }
    }
    return -1;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>n>>m;
    cin>>a>>b;
    cin>>c>>d;

    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<bfs()<<"\n";
    return 0;
}  