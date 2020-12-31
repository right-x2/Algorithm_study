#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> v;
int n,m;
int ans = -1;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int s,e;
    int cnt = 0;
    s = 0;
    e = 0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }

    if(v[0]==1) cnt++;

    while(e<n)
    {
        if(cnt==m&&(ans>e-s+1||ans==-1)) ans = e-s+1;
        if(cnt<m)
        {
            e++;
            if(v[e]==1) cnt++;
        }
        else
        {
            if(v[s]==1) cnt--;
            s++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}