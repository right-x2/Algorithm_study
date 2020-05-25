#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map<long long,long long> mp;
long long n,m;
long long bfs()
{
    queue< pair<long long,long long> >q;
    q.push(make_pair(n,0));
    while(!q.empty())
    {
        long long num = q.front().first;
        long long cnt = q.front().second;
        q.pop();
        if(num==m) return cnt;

        if(mp.find(num*2)==mp.end()&&num*2<=m)
        {
            mp.insert(make_pair(num*2,cnt+1));
            q.push(make_pair(num*2,cnt+1));
        }
        if(mp.find(num*10+1)==mp.end()&&num*10+1<=m)
        {
            mp.insert(make_pair(num*10+1,cnt+1));
            q.push(make_pair(num*10+1,cnt+1));
        }
    }
    return -2;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin>>n>>m;

    cout<<bfs()+1<<"\n";
}   