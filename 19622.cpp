#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,pair<int,int> > > v;
int n;
int arr[100001];

int solve(int cnt, int idx)
{
    if(cnt>=n) return 0;
    if(arr[cnt]>0) return arr[cnt];
    return arr[cnt] = max(solve(cnt+1,v[cnt+1].second.first),solve(cnt+2,v[cnt+2].second.first)+v[cnt].second.second);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    int ans = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b>>c;
        v.push_back(make_pair(a,make_pair(b,c)));
    }
    sort(v.begin(),v.end());


    ans = max(solve(0,v[0].second.first),solve(1,v[1].second.first));
    
    cout<<ans<<"\n";
    return 0;
}  