#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;


vector<pair<int,int> > v[100001];
int chk[100001];
int num[100001];
vector<int> temp;
int n,ans;

int solve(int idx)
{   

    priority_queue<pair<int,int>, vector<pair<int,int>, greater<pair<int,int> > > pq;

    pq.push(make_pair(0,idx));
    chk[idx] = 1;
    while(!pq.empty())
    {
        int tp = pq.front();
        pq.pop();

        for (int i = 0; i < v[idx].size(); ++i)
        {
            if(chk[v[idx][i].second])
            {
                chk[v[idx][i].second] = 1;
            }
        }
    }
    return num[idx];
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a,b,c;
    int dis;
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
    return 0;
}