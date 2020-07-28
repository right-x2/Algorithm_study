#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int s,e;
int answer = -1;
int chk[100001];
vector<int> ans;
int bfs()
{
    queue< pair<int,int>  >q;
    chk[s] = -1;
    q.push(make_pair(s,0));
    while(!q.empty())
    {
        int p = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(p==e)
        {
            answer = cnt;
            ans.push_back(e);
            int alcnt = 0;
            while(1)
            {
                int idx = chk[p];
                if(idx==-1) return 0;
                ans.push_back(idx);
                p = idx;
            }
            
            return 0;
        }
        if(p<e&&p*2<100001&&chk[p*2]==-2)
        {
            chk[p*2]=p;
            q.push(make_pair(p*2,cnt+1));
        }
        if(p>0&&chk[p-1]==-2)
        {
            chk[p-1]=p;
            q.push(make_pair(p-1,cnt+1));
        }
        if(p<e&&chk[p+1]==-2)
        {
            chk[p+1]=p;
            q.push(make_pair(p+1,cnt+1));
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>s>>e;
    for (int i = 0; i < 100001; ++i)
    {
        chk[i] = -2;
    }
    bfs();

    cout<<answer<<"\n";

    for (int i = ans.size()-1; i >= 0; --i)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}