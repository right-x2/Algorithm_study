#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<pair<int,int> > v[801];
vector<int> temp;
int flag = 0;
int chk[801];
int n,m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for (int i = 0; i < 2; ++i)
    {
        cin>>a;
        temp.push_back(a);
    }
    return 0;
}