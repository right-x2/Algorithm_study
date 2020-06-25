#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int m;
int k;
int way = 1;
int y = 1,x = 1;
int arr[101][101];
int ans;
int flag;
queue<pair<int,int> >q;
queue<pair<int,char> >pq;
void run()
{
    int a;
    int b;
    if(way==0)
    {
        ans++;
        y--;
        if(y==0||arr[y][x]==1)
        {
            flag = 1;
        }
        else if(arr[y][x]==0)
        {
            q.push(make_pair(y,x));
            arr[y][x] = 1;
            a = q.front().first;
            b = q.front().second;
            arr[a][b] = 0;
            q.pop();
        }
        else if(arr[y][x]==2)
        {
            arr[y][x] = 1;
            q.push(make_pair(y,x));
        }
    }
    else if(way==1)
    {

        ans++;
        x++;
        if(x==n+1||arr[y][x]==1)
        {
            flag = 1;
        }
        else if(arr[y][x]==0)
        {
            q.push(make_pair(y,x));
            arr[y][x] = 1;
            a = q.front().first;
            b = q.front().second;
            arr[a][b] = 0;
            q.pop();
        }
        else if(arr[y][x]==2)
        {
            arr[y][x] = 1;
            q.push(make_pair(y,x));
        }
    }
    else if(way==2)
    {

        ans++;
        y++;
        if(y==n+1||arr[y][x]==1)
        {
            flag=1;
        }
        else if(arr[y][x]==0)
        {
            q.push(make_pair(y,x));
            arr[y][x] = 1;
            a = q.front().first;
            b = q.front().second;
            arr[a][b] = 0;
            q.pop();
        }
        else if(arr[y][x]==2)
        {
            arr[y][x] = 1;
            q.push(make_pair(y,x));
        }
    }
    else if(way==3)
    {
        ans++;
        x--;
        if(x==0||arr[y][x]==1)
        {
            flag=1;
        }
        else if(arr[y][x]==0)
        {
            q.push(make_pair(y,x));
            arr[y][x] = 1;
            a = q.front().first;
            b = q.front().second;
            arr[a][b] = 0;
            q.pop();
        }
        else if(arr[y][x]==2)
        {
            arr[y][x] = 1;
            q.push(make_pair(y,x));
        }
    }
    if(!pq.empty()&&ans==pq.front().first)
    {
        if(pq.front().second=='D')
        {
            if(way==0) way = 1;
            else if(way==1) way = 2;
            else if(way==2) way = 3;
            else if(way==3) way = 0;
        }
        else if(pq.front().second=='L')
        {
            if(way==0) way = 3;
            else if(way==1) way = 0;
            else if(way==2) way = 1;
            else if(way==3) way = 2;
        }
        pq.pop();
    }
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    char c;
    int a,b;
    cin>>n;
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b;
        arr[a][b] = 2;
    }
    arr[0][0] = 1;
    q.push(make_pair(0,0));
    cin>>k;
    for (int i = 0; i < k; ++i)
    {
        cin>>a>>c;
        pq.push(make_pair(a,c));
    }
    while(flag==0) run();
    cout<<ans<<"\n";
    return 0;
}