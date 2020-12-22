#include <vector>
#include <iostream>
#include <stack>

using namespace std;


string solve(string str)
{
    string ans;
    stack<char> stk;
    int cnt = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            ans += str[i];
            cnt++;
        }
        else
        {
            if(stk.empty()) stk.push(str[i]);
            else
            {
                if(str[i]=='(') stk.push(str[i]);
                else if(str[i]==')')
                {
                    while(1)
                    {
                        char tmp = stk.top();
                        stk.pop();
                        if(tmp=='(') break;
                        else
                        {
                            cnt--;
                            ans += tmp;
                        }
                    }                    
                }
                else if(str[i]=='*'||str[i]=='/')
                {
                    if(stk.top()=='('||stk.top()=='+'||stk.top()=='-') stk.push(str[i]);
                    else
                    {
                        while(cnt>1)
                        {
                            if(stk.top()=='('||stk.top()=='+'||stk.top()=='-')break;
                            ans += stk.top();
                            stk.pop();   
                            cnt--;                         
                        }
                        stk.push(str[i]);
                    }
                }
                else if(str[i]=='+'||str[i]=='-')
                {
                    if(stk.top()=='(') stk.push(str[i]);
                    else
                    {
                        while(cnt>1)
                        {
                            if(stk.top()=='(')break;
                            ans += stk.top();
                            stk.pop(); 
                            cnt--;                            
                        }
                        stk.push(str[i]);
                    }
                }
            }
        }
    }
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;

    cin>>str;

    cout<<solve(str)<<"\n";
    return 0;
}