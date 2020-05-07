#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[100001];
vector<int> v[100001];
int n;

int bfs()
{
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int tp = q.front();
        q.pop();
        for (int i = 0; i < v[tp].size(); ++i)
        {
            if(arr[v[tp][i]]==0)
            {
                q.push(v[tp][i]);
                arr[v[tp][i]] = tp;
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
    int a,b;

    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    for (int i = 2; i <=n ; ++i)
    {
        cout<<arr[i]<<"\n";
    }
    return 0;
}  