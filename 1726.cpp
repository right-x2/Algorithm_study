#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int chk[101][101][4];
int arr[101][101];
int n,m;
int x,y,z;
int ans = 0;

struct Robot
{
    int y;
    int x;
    int way;
    bool operator<(const Robot& b) const{
           return this->x < b.x || this->y < b.y;
    }
};

priority_queue<pair<int,Robot>, vector<pair<int,Robot> >, greater<pair<int,Robot> > >pq;
int bfs()
{
    while(!pq.empty())
    {
        int cnt = pq.top().first;
        int a = pq.top().second.y;
        int b = pq.top().second.x;
        int way = pq.top().second.way;

       // cout<<a<<" "<<b<<" "<<way<<" "<<cnt<<"\n";
        if(a==y&&b==x&&way==z) 
        {
            ans = cnt;
            return 0;
        }
        pq.pop();
        if(way==2)
        {
            if(chk[a][b][3]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 3;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][3] = 1;
            }

            if(chk[a][b][4]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 4;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][4] = 1;
            }

            if(b-3>0&&chk[a][b-3][way]==0&&arr[a][b-3]==0&&arr[a][b-2]==0&&arr[a][b-1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b-3;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b-3][way] = 1;
            }

            if(b-2>0&&chk[a][b-2][way]==0&&arr[a][b-2]==0&&arr[a][b-1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b-2;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b-2][way] = 1;
            }
            if(b-1>0&&chk[a][b-1][way]==0&&arr[a][b-1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b-1;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b-1][way] = 1;
            }
        }
        else if(way==3)
        {
            if(chk[a][b][1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 1;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][1] = 1;
            }

            if(chk[a][b][2]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 2;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][2] = 1;
            }

            if(a+3<=n&&chk[a+3][b][way]==0&&arr[a+3][b]==0&&arr[a+2][b]==0&&arr[a+1][b]==0)
            {
                Robot temp;
                temp.y = a+3;
                temp.x = b;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a+3][b][way] = 1;
            }

            if(a+2<=n&&chk[a+2][b][way]==0&&arr[a+2][b]==0&&arr[a+1][b]==0)
            {
                Robot temp;
                temp.y = a+2;
                temp.x = b;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a+2][b][way] = 1;
            }

            if(a+1<=n&&chk[a+1][b][way]==0&&arr[a+1][b]==0)
            {
                Robot temp;
                temp.y = a+1;
                temp.x = b;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a+1][b][way] = 1;
            }
        }
        else if(way==1)
        {
            if(chk[a][b][3]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 3;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][3] = 1;
            }
            if(chk[a][b][4]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 4;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][4] = 1;
            }

            if(b+3<=m&&chk[a][b+3][way]==0&&arr[a][b+3]==0&&arr[a][b+2]==0&&arr[a][b+1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b+3;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b+3][way] = 1;
            }
            if(b+2<=m&&chk[a][b+2][way]==0&&arr[a][b+2]==0&&arr[a][b+1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b+2;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b+2][way] = 1;
            } 
            if(b+1<=m&&chk[a][b+1][way]==0&&arr[a][b+1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b+1;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b+1][way] = 1;
            }             
        }
        else if(way==4)
        {
            if(chk[a][b][2]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 2;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][way-1] = 1;
            }  

            if(chk[a][b][1]==0)
            {
                Robot temp;
                temp.y = a;
                temp.x = b;
                temp.way = 1;

                pq.push(make_pair(cnt+1,temp));
                chk[a][b][1] = 1;
            }
            if(a-3>0&&chk[a-3][b][way]==0&&arr[a-3][b]==0&&arr[a-2][b]==0&&arr[a-1][b]==0)
            {
                Robot temp;
                temp.y = a-3;
                temp.x = b;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a-3][b][way] = 1;
            }
            if(a-2>0&&chk[a-2][b][way]==0&&arr[a-2][b]==0&&arr[a-1][b]==0)
            {
                Robot temp;
                temp.y = a-2;
                temp.x = b;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a-2][b][way] = 1;
            }   
            if(a-1>0&&chk[a-1][b][way]==0&&arr[a-1][b]==0)
            {
                Robot temp;
                temp.y = a-1;
                temp.x = b;
                temp.way = way;

                pq.push(make_pair(cnt+1,temp));
                chk[a-1][b][way] = 1;
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
    int a,b,c;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin>>arr[i][j];
        }
    }
    Robot s;
    cin>>a>>b>>c;
    s.y = a;
    s.x = b;
    s.way = c;
    pq.push(make_pair(0,s));
    chk[a][b][c] = 1;
    cin>>y>>x>>z;
    bfs();
    cout<<ans<<"\n";
    return 0;
}