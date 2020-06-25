#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char arr[51][51];
int chk[51][51][2];
int n;
int ans = 0;
struct T
{
    int way;
    int x;
    int y;
};

T t;
T s;
int bfs()
{
    queue<T> q;
    q.push(t);
    while(!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int way = q.front().way;
        q.pop();
        if(y==s.y&&x==s.x&&way==s.way)
        {
            ans = chk[y][x][way];
            return 0;
        }
        if(way==0)
        {
            if(y+1<n&&chk[y+1][x][way]==0&&arr[y+1][x]!='1'&&arr[y+1][x-1]!='1'&&arr[y+1][x+1]!='1')
            {
                chk[y+1][x][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y+1;
                tmp.x = x;
                tmp.way = way;
                q.push(tmp);
            }
            if(x+2<n&&chk[y][x+1][way]==0&&arr[y][x+2]!='1')
            {
                chk[y][x+1][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y;
                tmp.x = x+1;
                tmp.way = way;
                q.push(tmp);
            }
            if(y-1>=0&&chk[y-1][x][way]==0&&arr[y-1][x]!='1'&&arr[y-1][x-1]!='1'&&arr[y-1][x+1]!='1')
            {
                chk[y-1][x][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y-1;
                tmp.x = x;
                tmp.way = way;
                q.push(tmp);
            }
            if(x-2>=0&&chk[y][x-1][way]==0&&arr[y][x-2]!='1')
            {
                chk[y][x-1][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y;
                tmp.x = x-1;
                tmp.way = way;
                q.push(tmp);
            }
            if(y+1<n&&y-1>=0&&chk[y][x][1]==0&&arr[y+1][x]!='1'&&arr[y+1][x-1]!='1'&&arr[y+1][x+1]!='1'&&arr[y-1][x]!='1'&&arr[y-1][x-1]!='1'&&arr[y-1][x+1]!='1')
            {
                chk[y][x][1] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y;
                tmp.x = x;
                tmp.way = 1;
                q.push(tmp);
            }
        }    
        else if(way==1)
        {
            if(y+2<n&&chk[y+1][x][way]==0&&arr[y+1][x]!='1')
            {
                chk[y+1][x][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y+1;
                tmp.x = x;
                tmp.way = way;
                q.push(tmp);
            }
            if(x+1<n&&chk[y][x+1][way]==0&&arr[y][x+1]!='1'&&arr[y+1][x+1]!='1'&&arr[y-1][x+1]!='1')
            {
                chk[y][x+1][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y;
                tmp.x = x+1;
                tmp.way = way;
                q.push(tmp);
            }
            if(y-2>=0&&chk[y-1][x][way]==0&&arr[y-2][x]!='1')
            {
                chk[y-1][x][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y-1;
                tmp.x = x;
                tmp.way = way;
                q.push(tmp);
            }
            if(x-1>=0&&chk[y][x-1][way]==0&&arr[y][x-1]!='1'&&arr[y+1][x-1]!='1'&&arr[y-1][x-1]!='1')
            {
                chk[y][x-1][way] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y;
                tmp.x = x-1;
                tmp.way = way;
                q.push(tmp);
            }
            if(x+1<n&&x-1>=0&&chk[y][x][0]==0&&arr[y][x+1]!='1'&&arr[y+1][x+1]!='1'&&arr[y-1][x+1]!='1'&&arr[y][x-1]!='1'&&arr[y+1][x-1]!='1'&&arr[y-1][x-1]!='1')
            {
                chk[y][x][0] = chk[y][x][way] + 1;
                T tmp;
                tmp.y = y;
                tmp.x = x;
                tmp.way = 0;
                q.push(tmp);
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
    string str;
    queue<pair<int,int> >q;
    queue<pair<int,int> >pq;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for(int j = 0; j <n; j++)
        {
            arr[i][j] = str[j];
            if(arr[i][j]=='B') q.push(make_pair(i,j));
            else if(arr[i][j]=='E')pq.push(make_pair(i,j));
        }
    }




    int a = q.front().first;
    q.pop();
    int b = q.front().first;
    t.y = q.front().first;
    t.x = q.front().second;
    if(a==b) t.way = 0;
    else t.way = 1;

    chk[t.y][t.x][t.way] = 1;


    a = pq.front().first;
    pq.pop();
    b = pq.front().first;
    s.y = pq.front().first;
    s.x = pq.front().second;
    if(a==b) s.way = 0;
    else s.way = 1;
    bfs();  

    if(ans==0) cout<<0<<"\n";
    else cout<<ans-1<<"\n";
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}