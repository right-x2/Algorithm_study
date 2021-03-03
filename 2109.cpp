#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
public:
    int p;
    int d;

    Point(int p, int d)
    {
        this->p = p;
        this->d = d;
    }
};

struct cmp
{
    bool operator()(Point &a, Point &b){
        if(a.p==b.p) return a.d>b.d;
        return a.p<b.p;
    }
};

int n;
int chk[10001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b,c;
    priority_queue<Point, vector<Point>, cmp> q;

    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        q.push(Point(a,b));
    }
    
    int ans = 0;

    while(!q.empty())
    {
        int p = q.top().p;
        int d = q.top().d;
        q.pop();
        for (int i = d; i >= 1; i--)
        {
            if(chk[i]==0)
            {
                ans = ans + p;
                chk[i] = 1;
                break;
            }
        }
        
    }


    cout<<ans<<"\n";
    return 0;
}