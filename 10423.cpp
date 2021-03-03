#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m,k;
class Edge{
public:
    int s;
    int e;
    int cost;

    Edge(int s, int e, int cost){
        this->s = s;
        this->e = e;
        this->cost = cost;
    }

    bool operator<(Edge &edge){
        return this->cost<edge.cost;
    }
};

vector<Edge> v;
int parent[100001];

int getParent(int idx)
{
    if(idx==parent[idx]) return idx;
    else return parent[idx] = getParent(parent[idx]);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    int ans = 0;
    cin>>n>>m>>k;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < k; i++)
    {
        /* code */
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        v.push_back(Edge(a,b,c));
    }
    
    sort(v.begin(),v.end());

    for(int i = 0; i < v.size(); i++)
    {
        int sp = getParent(v[i].s);
        int ep = getParent(v[i].e);
        int cost = v[i].cost;

        if(sp!=ep)
        {
            ans = ans + cost;
            if(sp>ep) parent[sp] = ep;
            else parent[ep] = sp;
        }
    }

    cout<<ans<<"\n";
    return 0;
}