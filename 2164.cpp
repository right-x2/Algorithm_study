#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    queue<int> q;
    int n;
    cin>>n;
    for (int i = 1; i <=n ; ++i)
    {
        q.push(i);
    }
    int cnt = 0;
    int k = 0;
    while(!q.empty())
    {
        cnt++;
        k = q.front();
        q.pop();
        if(cnt%2==1) continue;
        else q.push(k);
    }
    cout<<k<<"\n";
    return 0;
}  