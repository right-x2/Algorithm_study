#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;


vector<pair<int,int> > v[100001];
int chk[100001];
vector<int> temp;
int n;

int solve(int idx)
{
    for (int i = 0; i < v[idx].size(); ++i)
    {
        if()
    }

    return chk[idx];
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a,b,c;

    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        temp.push_back(a);
        while(1)
        {
            cin>>b;
            if(b==-1) break;
            cin>>c;
            v[a].push_back(make_pair(b,c));
        }
    }

    for (int i = 0; i < temp.size(); ++i)
    {
        if(chk[temp[i]]==0) solve(temp[i]);
    }
    return 0;
}