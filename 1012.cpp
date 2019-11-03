#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
int arr[51][51];
int c[51][51];
int m;
int n;

int dfs(int y, int x)
{
	c[y][x]=1;
	int cx[4] = {1, -1, 0, 0};
	int cy[4] = {0, 0, -1, 1};

	for (int i = 0; i < 4; ++i)
	{
		if(cx[i]+x>=0&&cx[i]+x<m&&cy[i]+y>=0&&cy[i]+y<n)
			if(arr[cy[i]+y][cx[i]+x]==1&&c[cy[i]+y][cx[i]+x]==0)
			{
				dfs(cy[i]+y,cx[i]+x);
			}
	}
}
int clean(int n, int m)
{
	for (int j = 0; j < n; ++j)
	{
		for (int k = 0; k < m; ++k)
		{
			arr[j][k]=0;
			c[j][k]=0;
		}		
	}
}

int main()
{
	int t,x,y,p;
	int cnt = 0;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>m>>n>>p;
		for (int j = 0; j < p; ++j)
		{
			cin>>x>>y;
			arr[y][x] = 1;
		}
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if(c[j][k]==0&&arr[j][k]==1)
				{
					cnt++;
					dfs(j,k);
				}
			}		
		}
		if(i==t-1) cout<<cnt<<"";
		else cout<<cnt<<"\n";
		clean(n,m);
		cnt = 0;

	}
	
}