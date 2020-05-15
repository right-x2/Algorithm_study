#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


string solve(string str)
{
	cout<<str<<"  fasf\n";
	stack<char> stk;
	for (int i = 0; i < str.length(); ++i)
	{
		if(str[i]==']'||str[i]==')')
		{
			stk.push(str[i]);
		}
		else if(str[i]=='('||str[i]=='[')
		{
			if(!stk.empty()&&stk.top()==str[i])
			{
				stk.pop();
			}
		}
	}
	if(stk.empty()) return "yes";
	else return "no";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    string str="";
    while(true)
    {
    	cin.getline(str,10);
    	if(str==".") break;
    	else cout<<solve(str)<<"\n";
    }
    return 0;
}  