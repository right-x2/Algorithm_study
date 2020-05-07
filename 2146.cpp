#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[101][101];
int chk[101][101];
int n;
int mn = 200;
int cnt = 1;
queue<pair<int,int> >q;

int search(int i, int j)
{
    queue< pair<int,int> > temp;
    temp.push(make_pair(i,j));
    arr[i][j] = cnt;
    while(!temp.empty())
    {
        int count = 0;
        int y = temp.front().first;
        int x = temp.front().second;
        temp.pop();
        if(y+1<n)
        {
            if(arr[y+1][x]==1) 
            {
                temp.push(make_pair(y+1,x));
                arr[y+1][x] = cnt;
            }
            else if(arr[y+1][x]==0) count = 1;
        }
        if(y-1>=0)
        {
            if(arr[y-1][x]==1) 
            {
                temp.push(make_pair(y-1,x));
                arr[y-1][x] = cnt;
            }
            else if(arr[y-1][x]==0) count = 1;
        }
        if(x-1>=0)
        {
            if(arr[y][x-1]==1) 
            {
                temp.push(make_pair(y,x-1));
                arr[y][x-1] = cnt;
            }
            else if(arr[y][x-1]==0) count = 1;
        }
        if(x+1<n)
        {
            if(arr[y][x+1]==1) 
            {
                temp.push(make_pair(y,x+1));
                arr[y][x+1] = cnt;
            }
            else if(arr[y][x+1]==0) count = 1;
        }

        if(count==1) q.push(make_pair(y,x));
    }
    return 0;
}

int bfs()
{
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(chk[y][x]==mn+2) return -1;
        if(arr[y][x]==1)
        {
            return chk[y][x]-2;
        } 
        if(chk[y][x]==0) chk[y][x] = 1;
        if(y+1<n)
        {
            if((arr[y+1][x]==1||arr[y+1][x]==0)&&chk[y+1][x]==0) 
            {
                q.push(make_pair(y+1,x));
                chk[y+1][x] = chk[y][x]+1;
            }
        }
        if(y-1>=0)
        {
            if((arr[y-1][x]==1||arr[y-1][x]==0)&&chk[y-1][x]==0) 
            {
                q.push(make_pair(y-1,x));
                chk[y-1][x] = chk[y][x]+1;
            }
        }
        if(x-1>=0)
        {
            if((arr[y][x-1]==1||arr[y][x-1]==0)&&chk[y][x-1]==0) 
            {
                q.push(make_pair(y,x-1));
                chk[y][x-1] = chk[y][x]+1;
            }
        }
        if(x+1<n)
        {
            if((arr[y][x+1]==1||arr[y][x+1]==0)&&chk[y][x+1]==0) 
            {
                q.push(make_pair(y,x+1));
                chk[y][x+1] = chk[y][x]+1;
            }
        }
    }
    return -1;
}

void clear()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            chk[i][j] = 0;
        }
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
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j]==1)
            {
                cnt++;
                search(i,j);
                int k = bfs();
                if(k!=-1&&mn>k) mn = k;
                clear();
            }
            while(!q.empty())
            {
                q.pop();
            }
        }
    }
    cout<<mn<<"\n";
    return 0;
}  