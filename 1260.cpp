#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector<int> v[1002];
vector<int> iv;
vector<int> answer;
int arr[1002] = {0,};
void bfs(int a)
{
	queue<int> que;
	arr[a] = 1;
	
	answer.push_back(a);
	for (int i = 0; i < v[a].size(); ++i)
	{
		if(arr[v[a][i]]==0) 
		{

			iv.push_back(v[a][i]);

			arr[v[a][i]] = 1;
		}
	}
	sort(iv.begin(),iv.end());
	for (int i = 0; i < iv.size(); ++i)
	{
		que.push(iv[i]);
	}
	iv.clear();

	while(!que.empty())
	{

		int frt = que.front();
		que.pop();
		answer.push_back(frt);
		for (int i = 0; i < v[frt].size(); ++i)
		{
			iv.push_back(v[frt][i]);
		}
		sort(iv.begin(),iv.end());
		for (int i = 0; i < iv.size(); ++i)
		{
			
			if(arr[iv[i]]==0)
			{

				que.push(iv[i]);
				arr[iv[i]] = 1;
			}
		}
		iv.clear();
	}
	for (int i = 0; i < answer.size(); ++i)
	{
		cout<<answer[i]<<" ";
	}

}

void dfs(int a)
{
	stack<int> stk;
	stk.push(a); 
	while(!stk.empty())
	{
		int tp = stk.top();
		stk.pop();
		if(arr[tp]==0)
		{
			answer.push_back(tp);
			arr[tp] = 1;
		}
		for (int i = 0; i < v[tp].size(); ++i)
		{
			if(arr[v[tp][i]]==0)
			{
				iv.push_back(v[tp][i]);;
			}
		}
		sort(iv.begin(),iv.end());
		for (int i = 0; i < iv.size(); ++i)
		{
			stk.push(iv[iv.size()-1-i]);
		}
		iv.clear();
	}
	for (int i = 0; i < answer.size(); ++i)
	{
		cout<<answer[i]<<" ";
	}
	cout<<"\n"<<"";
	for (int i = 0; i <= 1000; ++i)
	{
		arr[i] = 0;
	}
	answer.clear();

}
int main()
{
	int n,m,a,b,c;
	cin>>n>>m>>a;

	for (int i = 0; i < m; ++i)
	{
		cin>>b>>c;
		v[b].push_back(c);
		v[c].push_back(b);
	}
	dfs(a);
	bfs(a);
	
}
