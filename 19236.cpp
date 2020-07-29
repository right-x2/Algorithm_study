#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int way[17];
int sy,sx;
int arr[4][4];
int sway = 0;
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};

int ans;


struct P
{
    int num;
    int y;
    int x;
};


P plc[17];

void change(int a,int y, int x)
{
    int w = a;
    for (int i = 0; i < 8; ++i)
    {
        if(w+i==9) w = w - 8;
        if(y+dy[w+i]>=0&&y+dy[w+i]<4&&x+dx[w+i]<4&&x+dx[w+i]>=0&&arr[y+dy[w+i]][x+dx[w+i]]!=-1)
        {
            if(arr[y+dy[w+i]][x+dx[w+i]]==0)
            {
                way[arr[y][x]] = w+i;
                arr[y+dy[w+i]][x+dx[w+i]] = arr[y][x];
                plc[arr[y+dy[w+i]][x+dx[w+i]]].y = y+dy[w+i];
                plc[arr[y+dy[w+i]][x+dx[w+i]]].x = x+dx[w+i];

                arr[y][x] = 0;
            }
            else
            {           
                way[arr[y][x]] = w+i;

                int tmp = arr[y][x];
                arr[y][x] = arr[y+dy[w+i]][x+dx[w+i]];
                arr[y+dy[w+i]][x+dx[w+i]] = tmp;

                
                plc[arr[y+dy[w+i]][x+dx[w+i]]].y = y+dy[w+i];
                plc[arr[y+dy[w+i]][x+dx[w+i]]].x = x+dx[w+i];

                plc[arr[y][x]].y = y;
                plc[arr[y][x]].x = x;
            }
            break;
        }
    }
}

int move()
{
    priority_queue< int,vector<int>,greater<int> >pq;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if(arr[i][j]!=0&&arr[i][j]!=-1)
            {
                pq.push(arr[i][j]);
            }
        }
    }

    while(!pq.empty())
    {
        int num = pq.top();
        int y = plc[num].y;
        int x = plc[num].x;
        change(way[num],y,x);
        pq.pop();
    }
    return 0;
}

int solve(int mx)
{
    move();
    int ty = sy;
    int tx = sx;
    int tway = sway;
    int bway[17];
    int box[4][4];
    P bplc[17];
    if(mx>ans) ans = mx;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            box[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < 17; ++i)
    {
        bway[i] = way[i];
        bplc[i] = plc[i];
    }
    for (int i = 1; i <= 4; ++i)
    {
        if(sy+dy[sway]*i>=0&&sy+dy[sway]*i<4&&sx+dx[sway]*i<4&&sx+dx[sway]*i>=0&&arr[sy+dy[sway]*i][sx+dx[sway]*i]!=0)
        {
            arr[sy][sx] = 0;
            int plus = arr[sy+dy[sway]*i][sx+dx[sway]*i];
            sy = sy+dy[sway]*i;
            sx = sx+dx[sway]*i;
            sway = way[arr[sy][sx]];
            arr[sy][sx] = -1;
            solve(mx+plus);
            sway = tway;
            sy = ty;
            sx = tx;
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    arr[j][k] = box[j][k];
                }
            }
            for (int j = 0; j< 17; ++j)
            {
                way[j] = bway[j];
                plc[j] = bplc[j];
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
    int a,b;
    int mx;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin>>a>>b;
            if(i==0&&j==0)
            {
                sway = b;
                mx = a;
                arr[i][j] = -1;
                continue;
            }
            else
            {
                arr[i][j] = a;
                way[a] = b;
                P p;
                p.num = a;
                p.y = i;
                p.x = j;
                plc[a] = p;                
            }
        }
    }



    solve(mx);

    cout<<ans<<"\n";
    return 0;
}