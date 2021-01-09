#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v[201];
int chk[201];
vector<int> s;
int arr[201][201];
int ans = 0;
int n,m;
int cnt = 1;

int bfs(int idx)
{
    queue<int> q;
    chk[idx] = cnt;
    q.push(idx);

    while(!q.empty())
    {
        int num = q.front();
        q.pop();

        for(int i = 0; i < v[num].size(); i++)
        {
            if(chk[v[num][i]]==0)
            {
                chk[v[num][i]] = cnt;
                q.push(v[num][i]);
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


    cin>>n;
    cin>>m;
    for (int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1) v[i].push_back(j);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin>>a;
        s.push_back(a);
    }


    for (int i = 1; i <= n; ++i)
    {
        if(chk[i]==0)
        {
            bfs(i);
            cnt++;
        }
        
    }

    int point = 0;
    for (int i = 0; i < m; ++i)
    {
        if(i==0)point = chk[s[i]];
        else
        {
            if(point!=chk[s[i]]) ans = 1;
        }
    }
    if(ans==0) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";


    return 0;
}