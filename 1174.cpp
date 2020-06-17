#include <vector>
#include <iostream>
#include <queue>
using namespace std;


long long mx = 9876543210;
long long ans = -1;
int cnt = 0;
int n;
priority_queue<long long,vector<long long>, greater<long long> >pq;


int bfs()
{
    while(!pq.empty())
    {
        long long tmp = pq.top();
        pq.pop();
        cnt++;
        if(cnt==n)
        {
            ans = tmp;
            return 0;
        }
        int k = tmp%10;
        tmp = tmp * 10;
        for (int i = 0; i <k ; ++i)
        {
            pq.push(tmp+i);
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long i = 0;
    
    cin>>n;
    while(i<10)
    {
        pq.push(i);
        i++;
    }
    bfs();
    cout<<ans<<"\n";
    return 0;
}