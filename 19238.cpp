#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,m,k;
int arr[21][21];
int tmp[21][21];
int dy[4] ={1,-1,0,0};
int dx[4] ={0,0,-1,1};
int answer;

int sy,sx;

struct P
{
    int y;
    int x;
};


P box[405];

int bfs(){
    priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

    queue<pair<int,pair<int,int> > >q;
    queue<pair<pair<int,int>,pair<int,int> > >dq;
    q.push(make_pair(0,make_pair(sy,sx)));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            arr[i][j] = tmp[i][j];
        }
    }

    while(!q.empty())
    {
        int cnt = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        
        q.pop();
        if(arr[y][x]>1)
        {
            pq.push(make_pair(cnt,make_pair(y,x)));
            continue;
        }
        for(int i = 0; i < 4;i++)
        {
            if(y+dy[i]<=n&&y+dy[i]>0&&x+dx[i]<=n&&x+dx[i]>0)
            {
                if(arr[y+dy[i]][x+dx[i]]==0)
                {
                    q.push(make_pair(cnt+1,make_pair(y+dy[i],x+dx[i])));
                    arr[y+dy[i]][x+dx[i]] = 1;
                }
                else if(arr[y+dy[i]][x+dx[i]]>1)
                {
              //      cout<<y+dy[i]<<" "<<x+dx[i]<<"\n";
                    pq.push(make_pair(cnt+1,make_pair(y+dy[i],x+dx[i])));
                    arr[y+dy[i]][x+dx[i]] = 1;
                }
            }
        }
    }
    if(pq.empty()||pq.top().first>k) return -1;

    int num = tmp[pq.top().second.first][pq.top().second.second];
    k = k - pq.top().first;
    dq.push(make_pair(make_pair(k,0),make_pair(pq.top().second.first,pq.top().second.second)));

    tmp[pq.top().second.first][pq.top().second.second] = 0;

  //  cout<<pq.top().second.first<<" "<<pq.top().second.second<<" "<<k<<"\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            arr[i][j] = tmp[i][j];
        }
    }
 //   cout<<num<<"\n";
    while(!dq.empty())
    {
        int sum = dq.front().first.first;
        int cnt = dq.front().first.second;
        int y = dq.front().second.first;
        int x = dq.front().second.second;

        dq.pop();
 //       cout<<y<<" "<<x<<" "<<sum<<"\n";
        if(y==box[num].y&&x==box[num].x)
        {
            k = k + cnt*2 -cnt;
            sy = y;
            sx = x;
            return 0;
        }

        if(sum==0) continue;

        for(int i = 0; i < 4;i++)
        {
            if(y+dy[i]<=n&&y+dy[i]>0&&x+dx[i]<=n&&x+dx[i]>0&&arr[y+dy[i]][x+dx[i]]!=1)
            {
                dq.push(make_pair(make_pair(sum-1,cnt+1),make_pair(y+dy[i],x+dx[i])));
                arr[y+dy[i]][x+dx[i]] = 1;
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
    int a,b,c,d;

    cin>>n>>m>>k;


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }

    cin>>sy>>sx;

    for (int i = 2; i < m+2; ++i)
    {
        cin>>a>>b>>c>>d;

        arr[a][b] = i;
        tmp[a][b] = i;

        P p;
        p.y = c;
        p.x = d;
        box[i] = p;
    }

    for (int i = 0; i < m; ++i)
    {
        if(bfs()==-1)
        {
            answer = -1;
            break;
        }
        else answer = k;
    }

    cout<<answer<<"\n";
    return 0;
}