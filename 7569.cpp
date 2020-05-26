#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int n,m,h;
int arr[101][101][101];
int temp[101][101][101];
int cnt;
int alcnt;
int box;
struct Point
{
    int y;
    int x;
    int z;
};
queue<Point> q;
int bfs()
{
    int y = q.front().y;
    int x = q.front().x;
    int z = q.front().z;
    q.pop();
    if(y+1<n&&arr[y+1][x][z]==0)
    {
        arr[y+1][x][z] = 1;
        Point p;
        p.y = y+1;
        p.x = x;
        p.z = z;
        q.push(p);
        box++;
    }
    if(y-1>=0&&arr[y-1][x][z]==0)
    {
        arr[y-1][x][z] = 1;
        Point p;
        p.y = y-1;
        p.x = x;
        p.z = z;
        q.push(p);
        box++;
    }
    if(x+1<m&&arr[y][x+1][z]==0)
    {
        arr[y][x+1][z] = 1;
        Point p;
        p.y = y;
        p.x = x+1;
        p.z = z;
        q.push(p);
        box++;
    }
    if(x-1>=0&&arr[y][x-1][z]==0)
    {
        arr[y][x-1][z] = 1;
        Point p;
        p.y = y;
        p.x = x-1;
        p.z = z;
        q.push(p);
        box++;
    }
    if(z+1<h&&arr[y][x][z+1]==0)
    {
        arr[y][x][z+1] = 1;
        Point p;
        p.y = y;
        p.x = x;
        p.z = z+1;
        q.push(p);
        box++;
    }
    if(z-1>=0&&arr[y][x][z-1]==0)
    {
        arr[y][x][z-1] = 1;
        Point p;
        p.y = y;
        p.x = x;
        p.z = z-1;
        q.push(p);
        box++;
    }
    return 0;
}
int check()
{
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                if(arr[j][k][i]==0) return 0;
            }
        }  
    }
    return 1;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>m>>n>>h;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                cin>>arr[j][k][i];
                temp[j][k][i] = arr[j][k][i];
                if(arr[j][k][i]==1)
                {
                    cnt++;
                    Point p;
                    p.y = j;
                    p.x = k;
                    p.z = i;
                    q.push(p);
                }
            }
        }
    }
    if(check()==1) cout<<0<<"\n";
    else
    {
        while(1)
        {
            if(q.empty())
            {
                cout<<-1<<"\n";
                break;
            }
            alcnt++;
            for (int i = 0; i < cnt; ++i)
            {
                bfs();
            }
            if(check()==1)
            {
                cout<<alcnt<<"\n";
                break;
            }
            cnt = box;
            box = 0;
        }
    }
}   