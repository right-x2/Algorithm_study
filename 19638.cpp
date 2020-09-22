#include <vector>
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int n,h,t;
int ans;
string answer = "NO";
priority_queue<int, vector<int>, less<int> >q;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>n>>h>>t;

    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        q.push(a);
    }

    for (int i = 0; i <= t; ++i)
    {
        a = q.top();
        q.pop();

        
        if(h>a)
        {
            ans = i;
            answer = "YES";
            break;
        }
        if(a==1) break;
        if(i==t)
        {
            q.push(a);
            break;
        } 
        q.push(a/2);
    }

    if(answer=="YES")
    {
        cout<<answer<<"\n";
        cout<<ans<<"\n";
    }
    else
    {
        cout<<answer<<"\n";
        cout<<q.top()<<"\n";
    }

    return 0;
}