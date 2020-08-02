#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;


int arr[1001];
int chk[1001][1001];
vector<int> v[1001];
int n,m;
int tp;
queue<int> q;
queue<int> ans;
int solve()
{
    int cnt = 0;
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();


        for(int i = 0; i < v[tp].size(); i++)
        {
            arr[v[tp][i]]--;
            if(arr[v[tp][i]]==0)
            {
                q.push(v[tp][i]);
            }
        }
        cnt++;
        ans.push(tp);
    }
    if(cnt!=n) return 1;
    else return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    int flag = 0;

    cin>>n>>m;

    for (int i = 0; i <m ; ++i)
    {
        cin>>c;
        a = -1;
        for (int j = 0; j < c; ++j)
        {
            cin>>b;
            if(a==-1)
            {
                a = b;
                continue;
            }
            else
            {
                chk[a][b] = 1;
                v[a].push_back(b);
                arr[b]++;  
                a = b;              
            }
        }
    }

        for (int i = 1; i <= n ; ++i)
        {
            if(arr[i]==0)q.push(i);
        }
        if(solve()==1) cout<<0<<"\n";
        else
        {
            while(!ans.empty())
            {
                cout<<ans.front()<<"\n";
                ans.pop();
            }
        }
    return 0;
}