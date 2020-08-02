#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
int arr[501];
int sum[501];
int cnt[501];

vector<int> v[501];

queue<int> q;

int solve()
{
    while(!q.empty())
    {

        int tp = q.front();
        q.pop();
        for (int i = 0; i < v[tp].size(); ++i)
        {
            cnt[v[tp][i]]--;
            if(sum[v[tp][i]]<sum[tp]) sum[v[tp][i]] = sum[tp];
            if(cnt[v[tp][i]]==0) 
            {
                sum[v[tp][i]] = sum[v[tp][i]] + arr[v[tp][i]];
                q.push(v[tp][i]);
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

    int a;
    int b;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a;
        arr[i] = a;
        while(1)
        {
            cin>>b;
            if(b==-1) 
            {
                if(cnt[i]==0) 
                {
                    sum[i] = a;
                    q.push(i);
                }
                break;
            }
            cnt[i]++;
            v[b].push_back(i);
        }
    }

    solve();

    for (int i = 1; i <=n ; ++i)
    {
        cout<<sum[i]<<"\n";
    }
    return 0;
}