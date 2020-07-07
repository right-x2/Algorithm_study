#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n,m,k;
int ans = -1;


int move[401][5][5];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
struct  Shark
{
    int y;
    int x;
    int num;
    int cnt;
    int way;
    int gbn;
};

struct cmp {
    bool operator()(const Shark &u, const Shark &v) {
        return u.num > v.num;
    }
};
vector<Shark> temp;
priority_queue<Shark,vector<Shark>,cmp> pq;
Shark arr[21][21];

int bfs()
{
    int cnt = 0;
    while(1)
    {
        cnt++;
        while(!pq.empty())
        {
            priority_queue<int,vector<int>,greater<int> > order;
            Shark s = pq.top();
            pq.pop();
            int y = s.y;
            int x = s.x;
            int way = s.way;
            int num = s.num;
            int flag = 0;
            for (int i = 1; i <= 4; ++i)
            {
                int idx = move[num][way][i]-1;
                if(y+dy[idx]<n&&y+dy[idx]>=0&&x+dx[idx]<n&&x+dx[idx]>=0&&arr[y+dy[idx]][x+dx[idx]]!=NULL)
                {
                    arr[y][x].gbn = 0;
                    temp.push_back(s);
                    flag = 1;
                    break;
                }
            }
        }
    }
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>n>>m>>k;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>a;
            if(a!=0)
            {
                Shark s;
                s.y = i;
                s.x = j;
                s.gbn = 1;
                s.num = a;    
                temp.push(s);            
            }
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        cin>>a;
        Shark s = temp.top();
        temp.pop();
        s.way = a;
        arr[s.y][s.x] = s;
        pq.push(s);
    }

    for (int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 1; k <= 4; k++)
            {
                cin>>a;
                move[i][j][k] = a;
            }
        }
    }
    bfs();
    cout<<ans<<"\n";
    return 0;
}