#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int INF = 30000000;
int arr[200001] ;
vector< pair<int, int> > pv[200001];

int bfs(int v, int sum)
{
    for (int i = 0; i < pv[v].size(); ++i)
    {
        if(sum+pv[v][i].second < arr[pv[v][i].first]) arr[pv[v][i].first] = sum+pv[v][i].second;
        bfs(pv[v][i].first,sum+pv[v][i].second);
    }
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int u,v,w,n,k,start;
    vector<int> ans;

    cin>>n>>k;
    cin>>start;
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = INF; 
    }
    arr[start] = 0;
    for (int i = 0; i < k; ++i)
    {
        cin>>u>>v>>w;
        pv[u].push_back(make_pair(v,w));
    }

    for (int i = 0; i < pv[start].size(); ++i)
    {
        arr[pv[start][i].first] = pv[start][i].second;
        bfs(pv[start][i].first,pv[start][i].second);
    }

    for (int i = 1; i <= n; ++i)
    {
        ans.push_back(arr[i]);
    }
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); ++i)
    {
        if(ans[i]>=3000000) cout<<"INF"<<"\n";
        else cout<<ans[i]<<"\n";
    }

    return 0;
}