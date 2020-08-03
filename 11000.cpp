#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int> >pv;
priority_queue<int,vector<int> ,greater<int> >pq;
int cnt = 1;

int solve()
{
    pq.push(pv[0].second);


    for (int i = 1; i < pv.size(); ++i)
    {
        if(pq.top()<=pv[i].first)
        {
            pq.pop();
            pq.push(pv[i].second);
        }
        else pq.push(pv[i].second);
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
        cin>>a>>b;
        pv.push_back(make_pair(a,b));
    }
    sort(pv.begin(),pv.end());
    solve();
    cout<<pq.size()<<"\n";
    return 0;
}