#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,int> >v;
int n,m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>n>>m;

    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(),v.end());
    int s = 0;
    int e = 1;
    int sum = v[s].first+v[e].first;
    int ans = sum;

 
    return 0;
}  