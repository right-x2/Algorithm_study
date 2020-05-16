#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

queue<int> q;
vector<int> v;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }
    int cnt = 0;
    if(n==1)
    {
       cout<<"<1>"<<"";
    }
    else
    {
        while(!q.empty())
        {
            cnt++;
            int tp = q.front();
            q.pop();
            if(cnt==m)
            {
                v.push_back(tp);
                cnt = 0;
            }
            else
            {
                q.push(tp);
            }
        }
        for (int i = 0; i <n ; ++i)
        {
            if(i==0)
            {
                cout<<"<"<<"";
                cout<<v[i]<<", ";
            }
            else if(i==n-1)
            {
                cout<<v[i]<<">";
            }
            else
            {
                cout<<v[i]<<", ";
            }
        }
    }
}  