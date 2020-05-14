#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<pair<int,int> >v;
    int n,a,b;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        v.push_back(make_pair(b,a));
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i].second<<" "<<v[i].first<<"\n";
    }
    return 0;
}  