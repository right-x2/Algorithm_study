#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int>v;
int n,m;

int solve(int idx,vector<int> ans)
{
    if(ans.size()==m)
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n"<<"";
        return 0;
    }
    for (int i = idx+1; i < v.size(); ++i)
    {
        ans.push_back(v[i]);
        solve(i,ans);
        ans.pop_back();
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> ans;
    int num;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i)
    {
        ans.push_back(v[i]);
        solve(i,ans);
        ans.pop_back();
    }
    return 0;
}  