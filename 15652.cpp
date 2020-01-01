#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

int dfs(int n,vector<int> pv,int m, int s)
{
    vector<int> v = pv;
    int len = v.size();
    if(pv.size()==m)    
    {
        for (int i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<" ";
        }
        cout<<""<<"\n";
        return 0;
    }
    int cnt = 0;
    for (int i = s; i <= n; ++i)
    {
            v.push_back(i);
            dfs(n,v,m,i);
            v.pop_back();
        cnt = 0;
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> v;
    int m,n;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i);
        dfs(n,v,m,i);
        v.pop_back();
    }
    return 0;
}