#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int d,p;
int dp[100001];
int chk[100001];
vector<pair<int,int> >pv;

int solve(int idx)
{
    if(idx==0) return 0;
    int mx = 0;
    for (int i = 0; i < pv.size(); i++)
    {
        if(idx-pv[i].first<0) continue;
        if(chk[pv[i].first]==0)
        {
            chk[pv[i].first] = 1;
            mx = max(mx,solve(idx-pv[i].first));
            chk[pv[i].first] = 0;
        }
    }
    return mx;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>d>>p;

    for (int i = 0; i < p; i++)
    {
        cin>>a>>b;
        pv.push_back(make_pair(a,b));
    }

    cout<<solve(d)<<"\n";

    return 0;
}