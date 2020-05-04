#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt;
vector<int> v;
int n,m;


int solve(int idx, int sum)
{
    if(sum==m) cnt++;
    for (int i = idx+1; i < n; ++i)
    {
        solve(i,sum+v[i]);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    for (int i = 0; i < n; ++i)
    {
        solve(i,v[i]);
    }

    cout<<cnt<<"\n";
    return 0;
}