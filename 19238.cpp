#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int arr[401][401];
int tmp[401][401];

int earr[401][401];

long long sum;
int n,m;
int sx,sy;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};



int bfs()
{
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; ++j)
        {
            arr[i][j] = tmp[i][j];
        }
    }
    queue<pair<int,pair<int,int> > >q;
    q.push(make_pair(0,make_pair(sy,sx)));
    int ans = -1;
    int ay = -1;
    int ax = -1;
    int num = -1;

    if(arr[sy][sx]<1) arr[sy][sx] = 1;
    while(!q.empty())
    {
        int dis = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        cout<<y<<" "<<x<<" "<<dis<<" "<<arr[y][x]<<"\n";
        if(ans!=-1&&ans<dis) break;
        if(dis>sum) return -1;
        if(arr[y][x]>1)
        {
            if(ans==-1)
            {

                ans = dis;
                ay = y;
                ax = x;
                num = arr[y][x];
                if(dis==0) break;
            }
            else if(ans==dis)
            {
                if(y<ay)
                {
                    ans = dis;
                    ay = y;
                    ax = x;
                    num = arr[y][x];
                }
                else if(y==ay&&x<ax)
                {
                    ans = dis;
                    ay = y;
                    ax = x; 
                    num = arr[y][x];                   
                }
            }
            continue;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            if(y+dy[i]<=n&&y+dy[i]>0&&x+dx[i]<=n&&x+dx[i]>0&&(arr[y+dy[i]][x+dx[i]]!=1))
            {
                q.push(make_pair(dis+1,make_pair(y+dy[i],x+dx[i])));
                if(arr[y+dy[i]][x+dx[i]]<=1)arr[y+dy[i]][x+dx[i]] = 1;
            }
        } 
    }
    while(!q.empty()) q.pop();
    
    if(ans==-1) return -1;
    tmp[ay][ax] = 0;
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; ++j)
        {
            arr[i][j] = tmp[i][j];
        }
    }
    arr[ay][ax] = 1;
    q.push(make_pair(0,make_pair(ay,ax)));
    while(!q.empty())
    {
        int dis = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        cout<<y<<" "<<x<<" "<<dis<<" "<<earr[y][x]<<"\n";
        if(dis+ans>sum) return -1;
        if(earr[y][x]==num)
        {
            cout<<sum<<" "<<ans<<" "<<dis<<"----------\n";
            sum = sum-ans-dis+dis*2;
            sy = y;
            sx = x;
            return 0;
        }
        for (int i = 0; i < 4; ++i)
        {
            if(y+dy[i]<=n&&y+dy[i]>0&&x+dx[i]<=n&&x+dx[i]>0&&arr[y+dy[i]][x+dx[i]]!=1)
            {
                q.push(make_pair(dis+1,make_pair(y+dy[i],x+dx[i])));
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
    cin>>n>>m>>sum;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin>>arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }

    cin>>sy>>sx;

    for (int i = 2; i <= m+1; ++i)
    {
        cin>>a>>b>>c>>d;

        arr[a][b] = i;
        earr[c][d] = i;
        tmp[a][b] = i;
    }

    int answer = -1;
    
    for (int i = 0; i < m; ++i)
    {
        if(bfs()==-1)
        {
            answer = -1;
            break;
        }
        else
        {
            answer = sum;
        }
        cout<<answer<<" --answer\n";
    }
    
    cout<<answer<<"\n";
    return 0;
}