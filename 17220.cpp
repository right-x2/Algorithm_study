#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int alcnt;
vector<int> v[27];
vector<int> root;
int arr[27];
int c[27];
int d[27];
int chk[27];
int bfs(int k)
{
    queue<int> q;
    q.push(k);
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        for (int i = 0; i < v[idx].size(); ++i)
        {
            if(chk[v[idx][i]]==0&&arr[v[idx][i]]==0)
            {
                alcnt++;
                chk[v[idx][i]] = 1;
                q.push(v[idx][i]);
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
    
    char a,b;
    int k;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b;
        v[a-'A'].push_back(b-'A');
        c[a-'A']++;
        d[b-'A']++;
    }

    cin>>k;
    for (int i = 0; i < k; ++i)
    {
        cin>>a;
        arr[a-'A'] = 1;
    }
    for (int i = 0; i < 27; ++i)
    {
        if(c[i]!=0&&d[i]==0) root.push_back(i);
    }

    for (int i = 0; i < root.size(); ++i)
    {
        if(arr[root[i]]==0) bfs(root[i]);
    }

    cout<<alcnt<<"\n";
    return 0;
}