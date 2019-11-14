#include <iostream>
#include <string>
#include <stack>

using namespace std;

int check(string str)
{
	stack<char> stk;
	stack<char> con;
	char conp;
	for(int i = 0; i < str.length(); i++)
	{
		stk.push(str[i]);
	}
	if(stk.top()=='(') return 0;
	char top = stk.top();
	con.push(top);
	stk.pop();
	while(!stk.empty())
	{

		if(con.empty()) 
		{
			conp = stk.top();
			if(conp=='(') return 0;
			stk.pop();
			con.push(conp);
			if(stk.empty()) return 0;
		}
		else
		{
			conp = con.top();
		}
		if(conp=='(')
		{
			if(stk.top()==')')
			{
				stk.pop();
				con.pop();
				if(stk.empty()&&con.empty()) return 1;
				else if(stk.empty()&&!con.empty()) return 0;
				
			}
			else
			{
				top = stk.top();
				con.push(top);
				stk.pop();
				if(stk.empty()) return 0;
			}
		}
		else
		{
			if(stk.top()=='(')
			{
				stk.pop();
				con.pop();
				if(stk.empty()&&con.empty()) return 1;
				else if(stk.empty()&&!con.empty()) return 0;
				
			}
			else
			{
				top = stk.top();
				con.push(top);
				stk.pop();
				if(stk.empty()) return 0;
			}
		}
	}
	if(con.empty()) return 1;
	else return 0;
}

int main()
{
	int n;
	string str = "";
	cin>>n;
	for(int i = 0; i <n; i++)
	{
		cin>>str;
		if(check(str)==1) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}
