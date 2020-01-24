#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>


using namespace std;

int arr[1001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> v;
    vector<int> spc;
    queue<int> q;
    priority_queue<int,vector<int>,greater<int> > pq;
    int n,m,a,c,sum = 0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        spc.push_back(a);
        pq.push(i);
    }
    for (int i = 0; i < m; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    for (int i = 0; i < 2*m; ++i)
    {
        cin>>a;
        if(a>0)
        {
            a--;
            if(pq.empty())
            {
                q.push(a);
            }
            else
            {
                int tp = pq.top();
                pq.pop();
                sum = sum + spc[tp]*v[a];
                arr[a] = tp;
            }
        }
        else if(a<0)
        {
            a = -a -1;
            pq.push(arr[a]);
            while(!q.empty())
            {
                if(pq.empty()) break;
                int tp = pq.top();
                pq.pop();
                c = q.front();
                q.pop();
                sum = sum + spc[tp]*v[c];
                arr[c] = tp;
            }
        }
    }
    cout<<sum<<"\n";
    for (int i = 0; i <= m; ++i)
    {
        arr[i] = 0;
    }
}  