#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[51][51];
int chk[51][51];
vector<pair<int,int> >v[51][51];
vector<pair<int,int> >w[51][51];
int n,m; 
int cnt;
int space;

void clean()
{
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; j++)
        {
            chk[i][j] = 0;
        }
    }
}
int bfs(int y, int x)
{

    queue<pair<int,int> >q;
    q.push(make_pair(y,x));
    chk[y][x] = 1;
    int spc = 1;
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;

        q.pop();
        for (int i = 0; i < v[a][b].size(); ++i)
        {
            if(chk[v[a][b][i].first][v[a][b][i].second]==0)
            {
                spc++;
                chk[v[a][b][i].first][v[a][b][i].second] = 1;
                q.push(make_pair(v[a][b][i].first,v[a][b][i].second));
            }
        }
    }
    if(space<spc) space = spc;
    return 0;
}

int build(int y, int x, int num)
{
    //
    vector<int> s;
    while(num>0)
    {
        int mod = num%2;
        num = num/2;
        s.push_back(mod);
    }


    for (int i = s.size(); i <4 ; ++i)
    {
        s.push_back(0);
    }

 
    if(x-1>=0)
    {
        if(s[0]==0)
        {

            v[y][x].push_back(make_pair(y,x-1));
        }
        else
        {
            w[y][x].push_back(make_pair(y,x-1));
        }
    }

    if(y-1>=0)
    {

        if(s[1]==0)
        {
            v[y][x].push_back(make_pair(y-1,x));
        }
        else
        {
            w[y][x].push_back(make_pair(y-1,x));
        }        
    }

    if(x+1<m)
    {
        if(s[2]==0)
        {
            v[y][x].push_back(make_pair(y,x+1));
        }
        else
        {
            w[y][x].push_back(make_pair(y,x+1));
        }        
    }

    if(y+1<n)
    {
        if(s[3]==0)
        {
            v[y][x].push_back(make_pair(y+1,x));
        }
        else
        {
            w[y][x].push_back(make_pair(y+1,x));
        }           
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);


    cin>>m>>n;

    for(int i = 0; i < n; ++i)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            build(i,j,arr[i][j]);
        }
    }
    

    for(int i = 0; i < n; ++i)
    {
        for(int j=0; j<m; j++)
        {
            if(chk[i][j]==0) 
            {
                bfs(i,j);
                cnt++;
            }
        }
    }
    
    int ans = space;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j=0; j<m; j++)
        {
            for(int k = 0; k < w[i][j].size(); k++)
            {
                v[i][j].push_back(make_pair(w[i][j][k].first,w[i][j][k].second));
                bfs(i,j);
                clean();
                v[i][j].pop_back();
            }
        }
    }


    cout<<cnt<<" "<<ans<<" "<<space<<"\n";
    
    return 0;
}