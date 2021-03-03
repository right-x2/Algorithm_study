#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,int> >v[1001];
int n,m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    cin>>n>>m;

    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(c,b));
        v[b].push_back(make_pair(c,a));
    }
    return 0;
}