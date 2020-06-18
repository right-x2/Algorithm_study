#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

stack<pair<int, long long> >stk;
stack<pair<int, long long> >tmp;
int n;
int arr[500001];
void solve()
{
    while(!stk.empty())
    {
        if(tmp.empty())
        {
            int idx = stk.top().first;
            long long num = stk.top().second;
            tmp.push(make_pair(idx,num));
        }
        while(!tmp.empty())
        {
            if(stk.empty()) break;
            if(stk.top().second>tmp.top().second)
            {
               arr[tmp.top().first] =  stk.top().first;
               tmp.pop(); 
            }
            else break;
        }
        if(stk.empty()) break;
        tmp.push(make_pair(stk.top().first,stk.top().second));
        stk.pop();
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long num;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>num;
        stk.push(make_pair(i,num));
    }
    solve();
    for (int i = 1; i <= n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}