#include <vector>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long,vector<long long>,greater<long long> >pq;
long long n,m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long num;
    long long sum = 0,ans = 0;
    long long a,b;
    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        pq.push(num);
    }

    for (int i = 0; i < m; ++i)
    {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum = a+b;
        pq.push(sum);
        pq.push(sum);
    }

    while(!pq.empty())
    {
        ans = ans + pq.top();
        pq.pop();
    }
    cout<<ans<<"\n";
    return 0;
}