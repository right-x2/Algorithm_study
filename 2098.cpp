#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int n;
vector<int> dv[18];
int dfs(int y, int cost, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(i!=y)
		{
			dfs(i,dv[y][i],n);
		}
	}
}
int tsp(int y, int x,int n)
{
	for(int i = 0; i < n; i++)
	{
		if(i!=y)
		{
			dfs(i,dv[y][i],n);
		}
	}
}

int main()
{
	vector<int> v;
	
	int w;
	cin>>n;
	int arr[n] = {0,};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>w;
			dv[i].push_back(w);
		}
	}
}