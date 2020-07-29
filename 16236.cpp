#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int arr[401][401];
int temp[401][401];
int n;
int ay,ax;
int size=2;
int sum = 0;
int answer = 0;
int dy[4] = {0,-1,1,0};
int dx[4] = {-1,0,0,1};


int bfs()
{
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
    int cy = -1;
    int cx = -1;
    int cnt = -1;
    queue<pair<int,pair<int,int> > >q;
    q.push(make_pair(0,make_pair(ay,ax)));
    arr[ay][ax] = -1;
    while(!q.empty())
    {
        int dis = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        if(cnt!=-1&&cnt<dis) continue;
        if(arr[y][x]!=-1&&arr[y][x]<size)
        {
            if(cy==-1)
            {
                cnt = dis;
                cy = y;
                cx = x;
            }
            else if(y<cy)
            {
                cnt = dis;
                cy = y;
                cx = x;
            }
            else if(y==cy&&x<cx)
            {
                cnt = dis;
                cy = y;
                cx = x;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            if(y+dy[i]<n&&y+dy[i]>=0&&x+dx[i]<n&&x+dx[i]>=0&&arr[y+dy[i]][x+dx[i]]!=-1&&arr[y+dy[i]][x+dx[i]]<=size)
            {
                q.push(make_pair(dis+1,make_pair(y+dy[i],x+dx[i])));
                if(arr[y+dy[i]][x+dx[i]]==0||arr[y+dy[i]][x+dx[i]]==size) arr[y+dy[i]][x+dx[i]] = -1;
            }
        }
    }
    if(cnt==-1) return -1;
    else
    {
        answer = answer + cnt;
        temp[cy][cx] = 0;
        ay = cy;
        ax = cx;
        sum++;
        if(sum==size)
        {
            size++;
            sum = 0;
        }
        return 0;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==9)
            {
                ay = i;
                ax = j;
                temp[i][j] = 0;
            }
            else
            {
                temp[i][j] = arr[i][j];
            }
        }
    }
    while(1)
    {
        if(bfs()==-1)break;
    }
    cout<<answer<<"\n";
    return 0;
}