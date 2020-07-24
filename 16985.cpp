#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int arr[5][5][5];
int chk[5][5][5];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int ans = -1;
int temp[5][4][5][5];
int plate[5];

void turn(int idx,int s){
    vector<int>v;
    if(s==0)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                temp[idx][0][i][j] = arr[idx][i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                v.push_back(temp[idx][s-1][i][j]);
            }
            for (int j = 0; j < v.size(); ++j)
            {
                temp[idx][s][j][4-i] = v[j];
            }
            v.clear();
        }
    }
}
int bfs()
{
    queue<pair<pair<int,int>,pair<int,int> > >q;
    if(arr[0][0][0]==1) 
    {
        q.push(make_pair(make_pair(0,0),make_pair(0,0)));
        chk[0][0][0] = 1;
    }
    while(!q.empty())
    {
        int cnt = q.front().first.first;
        int z = q.front().first.second;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if(z==4&&y==4&&x==4)
        {
            if(ans==-1||ans>cnt) ans = cnt;
            return 0;
        }
        if(z+1<5&&arr[z+1][y][x]==1&&chk[z+1][y][x]==0)
        {
            chk[z+1][y][x] = 1;
            q.push(make_pair(make_pair(cnt+1,z+1),make_pair(y,x)));
        }
        for (int i = 0; i < 4; ++i)
        {
            if(y+dy[i]>=0&&y+dy[i]<5&&x+dx[i]>=0&&x+dx[i]<5&&arr[z][y+dy[i]][x+dx[i]]==1&&chk[z][y+dy[i]][x+dx[i]]==0)
            {
                chk[z][y+dy[i]][x+dx[i]] = 1;
                q.push(make_pair(make_pair(cnt+1,z),make_pair(y+dy[i],x+dx[i])));
            }
        }
        if(z-1>=0&&arr[z-1][y][x]==1&&chk[z-1][y][x]==0)
        {
            chk[z-1][y][x] = 1;
            q.push(make_pair(make_pair(cnt+1,z-1),make_pair(y,x)));
        }
    }
    return 0;
}

int dfs(int idx)
{
    if(idx==5)
    {
        bfs();
        for (int s = 0; s < 5; ++s)
        {
            for (int j = 0; j < 5; ++j)
            {
                for (int k = 0; k < 5; ++k)
                {
                    chk[s][j][k] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        if(plate[i]==1) continue;
        plate[i] = 1;
        for (int s = 0; s < 4; ++s)
        {
            for (int j = 0; j < 5; ++j)
            {
                for (int k = 0; k < 5; ++k)
                {
                    arr[idx][j][k] = temp[i][s][j][k];
                }
            }
            dfs(idx+1);
        }
        plate[i] = 0;
    } 
    return 0;   
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                cin>>arr[i][j][k];
            }
        }
        for (int j = 0; j < 4; ++j)
        {
            turn(i,j);
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        plate[i] = 1;
        for (int s = 0; s < 4; ++s)
        {
            for (int j = 0; j < 5; ++j)
            {
                for (int k = 0; k < 5; ++k)
                {
                    arr[0][j][k] = temp[i][s][j][k];
                }
            }
            dfs(1);
        }
        plate[i] = 0;
    }
    cout<<ans<<"\n";
    return 0;
}