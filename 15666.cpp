#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


vector<int>v;
int n,m;
int arr[100001];
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
    int temp=-1;
    for (int i = idx; i < v.size(); ++i)
    {
        if(v[i]!=temp)
        {
            ans.push_back(v[i]);
            arr[i] = 1;
            solve(i,ans);
            arr[i] = 0;
            temp = ans[ans.size()-1];
            ans.pop_back();
        }
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
    int temp = -1;
    for (int i = 0; i < n; ++i)
    {
        if(v[i]!=temp)
        {
            ans.push_back(v[i]);
            arr[i] = 1;
            solve(i,ans);
            arr[i] = 0;
            temp = ans[ans.size()-1];
            ans.pop_back();
        }
    }
    return 0;
}  