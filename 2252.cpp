#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;


int arr[32001];
vector<int> v[32001];
int n,m;
int tp;
queue<int> q;
queue<int> ans;
int solve()
{
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
        ans.push(tp);
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;

    cin>>n>>m;

    for (int i = 0; i <m ; ++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        arr[b]++;
    }

    for (int i = 1; i <= n ; ++i)
    {
        if(arr[i]==0)q.push(i);
    }
    solve();
    while(!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
}