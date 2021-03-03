#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Point{
public:
    int y;
    int x;
    int cnt;
    int k;
    Point(int y, int x, int cnt,int k){
        this->y = y;
        this->x = x;
        this->cnt = cnt;
        this->k = k;
    }
};


struct cmp
{
    bool operator()(Point &a, Point &b){
        return a.cnt>b.cnt;
    }
};

int chk[1001][1001][11];
int arr[1001][1001];
int n,m,maxk;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int solve()
{
    priority_queue<Point, vector<Point>, cmp> pq;
    pq.push(Point(0,0,1,0));

    while(!pq.empty())
    {

        int y = pq.top().y;
        int x = pq.top().x;
        int cnt = pq.top().cnt;
        int k = pq.top().k;
        pq.pop();
        if(chk[y][x][k]==1) continue;

        chk[y][x][k] = 1;
        if(y==n-1&&x==m-1) return cnt;
        for(int i = 0; i < 4; i++)
        {
            if(dy[i]+y>=0&& dy[i]+y<n&& dx[i]+x>=0&&dx[i]+x<m&&chk[dy[i]+y][dx[i]+x][k]==0)
            {
                if(arr[dy[i]+y][dx[i]+x]==0)
                {
                    pq.push(Point(dy[i]+y,dx[i]+x,cnt+1,k));
                }
                else
                {
                    if(k<maxk)
                    {
                        pq.push(Point(dy[i]+y,dx[i]+x,cnt+1,k+1));
                    }
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
    string str;
    cin>>n>>m>>maxk;

    for (int i = 0; i < n; i++)
    {
        cin>>str;
        for(int j = 0; j<m; j++)
        {
            arr[i][j] = str[j]-'0';
        }
    }
    cout<<solve()<<"\n";
    return 0;
}  