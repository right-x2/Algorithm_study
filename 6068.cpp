#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int INF = 987654321;
class Point{
public:
    int a;
    int b;

    Point(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};

struct cmp{
    bool operator()(Point &p,  Point &q)
    {
        if(p.b==q.b)return p.a<q.a;
        return p.b<q.b;
    }
};

priority_queue<Point,vector<Point>,cmp >pq;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    int a,b;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        pq.push(Point(a,b));
    }

    int ans = INF;
    while(!pq.empty())
    {
        a = pq.top().a;
        b = pq.top().b;
        pq.pop();
        if(ans<b)
        {
            ans = ans - a;
        }
        else
        {
            ans = b-a;
        }

    }
    if(ans<=0) cout<<-1<<"\n";
    else cout<<ans<<"\n";
    
    
    return 0;
}