#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int arr[21][21];
int ans[21];
int mn=100000;


int n;

int cal(int k)
{
    vector<int> p;
    vector<int> v;
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i)
    {
        if(ans[i]==0)
        {
            p.push_back(i);
        }
        else
        {
            v.push_back(i);
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i; j < v.size(); ++j)
        {
            a = a + arr[v[i]][v[j]]+arr[v[j]][v[i]];
            b = b + arr[p[i]][p[j]]+arr[p[j]][p[i]];
        }
    }
    if(mn>abs(a-b)) mn = abs(a-b);

    return 0;
}
int dfs(int k, int cnt)
{
    if(cnt==n/2)
    {
        cal(cnt);
        return 0;
    }
    for (int i = k+1; i < n; ++i)
    {
        ans[i] = 1;
        dfs(i,cnt+1);
        ans[i] = 0;
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

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i < n/2; ++i)
    {
        ans[i] = 1;
        dfs(i,1);
        ans[i] = 0;
    }

    cout<<mn<<"\n";
    return 0;
}  