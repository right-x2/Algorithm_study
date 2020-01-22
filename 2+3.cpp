#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

stack<int> stk;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, a;
    string str;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        if(str=="push")
        {
            cin>>a;
            stk.push(a);
        }
        else if(str=="top")
        {
            if(stk.empty()) cout<<-1<<"\n";
            else cout<<stk.top()<<"\n";
        }
        else if(str=="size")
        {
            cout<<stk.size()<<"\n";
        }
        else if(str=="empty")
        {
            if(stk.empty()) cout<<1<<"\n";
            else cout<<0<<"\n"; 
        }
        else if(str=="pop")
        {
            if(stk.empty()) cout<<-1<<"\n";
            else
            {
                cout<<stk.top()<<"\n";
                stk.pop();
            }
        }
    }
}  