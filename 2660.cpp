#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v[201];
vector<int>vp;
vector<int> s;
int chk[201];
int ans = -1;
int n,m;



int bfs(int idx)
{
    queue<pair<int,int> >q;
    q.push(make_pair(idx,0));
    chk[idx] = 1;
    int alcnt = 0;
    while(!q.empty())
    {
        int num = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if(cnt>alcnt) alcnt = cnt;
        for (int i = 0; i < v[num].size(); ++i)
        {
            if(chk[v[num][i]]==0)
            {
                chk[v[num][i]] = 1;
                q.push(make_pair(v[num][i],cnt+1));
            }
        }
    }

    if(ans==-1||alcnt==ans) 
    {
       vp.push_back(idx);
       ans = alcnt; 
    }
    else if(alcnt<ans)
    {
        ans = alcnt;
        vp.clear();
        vp.push_back(idx);
    }


    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;

    int point = 0;
    int a=0,b=0;

    while(1)
    {
        cin>>a>>b;
        if(a==-1&&b==-1) break;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        bfs(i);
        for(int j = 1; j <= n;j++)
        {
            chk[j] = 0;
        }
    }

    sort(vp.begin(),vp.end());



    cout<<ans<<" "<<vp.size()<<"\n";

    for (int i = 0; i < vp.size(); ++i)
    {
        cout<<vp[i]<<" ";
    }

    return 0;
}