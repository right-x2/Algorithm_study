#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int ans;
int chk[100001];
int arr[100001];
vector<int> tmp;
vector< pair<int,int> >v[100001];


int dfs(int idx, int sum)
{
    int flag = 0;
    for (int i = 0; i < v[idx].size(); ++i)
    {
        if(chk[v[idx][i].first]==0)
        {
            flag = 1;
            chk[v[idx][i].first] = 1;
            dfs(v[idx][i].first,sum+v[idx][i].second);
            chk[v[idx][i].first] = 0;
        }
    }
    if(flag==0)
    {
        if(ans<sum) ans = sum;
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
        arr[a]++;
        arr[b]++;
    }
    for (int i = 0; i < 100001; ++i)
    {
        if(arr[i]==1) tmp.push_back(i);
    }

    for (int i = 0; i < tmp.size(); ++i)
    {
        chk[tmp[i]] = 1;
        dfs(tmp[i],0);
        chk[tmp[i]] = 0;
    }

    cout<<ans<<"\n";
    return 0;
}