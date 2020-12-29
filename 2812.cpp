#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n,m;

int len;
vector<int> v;
stack<int> stk;
stack<int> ans;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    string str;
    cin>>n>>m;

    cin>>str;

    len = n-m;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(str[i]-'0');
    }
    
    stk.push(v[0]);

    for (int i = 1; i <v.size() ; ++i)
    {
        if(stk.top()<v[i])
        {
            while(!stk.empty())
            {
                if(stk.top()>=v[i]||stk.size()+v.size()-i==len) break;
                stk.pop();
            }
            stk.push(v[i]);
        }

        else if(stk.size()<len)
        {

            stk.push(v[i]);
        }
    }
    while(!stk.empty())
    {
        ans.push(stk.top());
        stk.pop();
    }

    while(!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
    }
    return 0;
}