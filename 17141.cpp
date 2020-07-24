#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<pair<int,int> >v;
vector<pair<int,int> >tmp;
int n,m;
int arr[70][70];
int dy[4] ={1,-1,0,0};
int dx[4] ={0,0,-1,1};
int ans = -1;
int zcnt = 0;
int solve()
{
    int cnt = 0;
    int num = m;
    int std = 0;
    int alcnt = 0;
    queue<pair<int,int> >q;
    for (int i = 0; i < tmp.size(); ++i)
    {
        q.push(make_pair(tmp[i].first,tmp[i].second));
        arr[tmp[i].first][tmp[i].second]=2;
    }
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            if(y+dy[i]>=0&&y+dy[i]<n&&x+dx[i]>=0&&x+dx[i]<n&&arr[y+dy[i]][x+dx[i]]==0)
            {
                std++;
                arr[y+dy[i]][x+dx[i]]=2;
                q.push(make_pair(y+dy[i],x+dx[i]));
            }
        }
        cnt++;
        if(cnt==num)
        {
            alcnt++;
            if(q.empty()) return 0;
            int flag = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(arr[i][j]==0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag==1)
                {
                    break;
                }
            }
            if(flag==0)
            {
                if(ans==-1||alcnt<ans) ans = alcnt;
                return 0;
            }
            cnt = 0;
            num = std;
            std = 0;
        }
    }
    return 0;
} 

int dfs(int s)
{
    if(tmp.size()==m)
    {
        solve();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][j]==2) arr[i][j] = 0;
            }
        }
        return 0;
    }
    for (int i = s; i < v.size(); ++i)
    {
        tmp.push_back(make_pair(v[i].first,v[i].second));
        dfs(i+1);
        tmp.pop_back();
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]==2) 
            {
               v.push_back(make_pair(i,j));
               arr[i][j] = 0; 
            }
            else if(arr[i][j]==0) zcnt++;

        }
    }
    cout<<zcnt<<"\n";
    if(zcnt==0&&v.size()==m) ans = 0;
    else
    {
        for (int i = 0; i < v.size(); ++i)
        {
            tmp.push_back(make_pair(v[i].first,v[i].second));
            dfs(i+1);
            tmp.pop_back();
        }
    }
    cout<<ans<<"\n";
    return 0;
}