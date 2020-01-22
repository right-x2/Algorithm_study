#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;
int arr[21][21];
int tmp[21][21];
int ans[21][21];
int c[21][21];
int mx = 0;
void right(int n)
{
	
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = n-2; j >= 0; j--)
		{
			if(arr[i][j]!=0)
			{
				int b = j;
				while(b<n)
				{
					b++;
					if(arr[i][b]!=0) break;
				}
				if(arr[i][b]!=0)
				{
					if(arr[i][b]==arr[i][j]&&c[i][b]==0)
					{
						arr[i][b] = arr[i][b]*2;
						arr[i][j] = 0;
						c[i][b] = 1;
						if(mx<arr[i][b]){
							mx = arr[i][b];
							cnt++;
						}
					}
					else
					{
						if(b-1==j)
						{
							continue;
						}
						else
						{
							arr[i][b-1] = arr[i][j];
							arr[i][j] = 0;
						}
						
					}
				}
				else
				{
					arr[i][b-1] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = 0;
		}
	}

}
void left(int n)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if(arr[i][j]!=0)
			{
				int b = j;
				while(b>0)
				{
					b--;
					if(arr[i][b]!=0) break;
				}
				if(b>-1)
				{
					if(arr[i][b]==arr[i][j]&&c[i][b]==0)
					{
						arr[i][b] = arr[i][b]*2;
						arr[i][j] = 0;
						c[i][b]=1;
						if(mx<arr[i][b]){
							mx = arr[i][b];
							cnt++;
						}
					}
					else
					{
						if(b+1==j)
						{
							continue;	
						}
						else
						{
							arr[i][b+1] = arr[i][j];
							arr[i][j] = 0;
						}
					}
				}
				else
				{
					arr[i][b+1] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = 0;
						c[b][j]=1;
						if(mx<arr[b][j]){
							cnt++;
							mx = arr[b][j];
						}
					}
					else
					{
						if(b+1==i)
						{
							continue;	
						}
						else
						{
							arr[b+1][j] = arr[i][j];
							arr[i][j] = 0;
		}
	}

}

void down(int n)
{
	for (int i = n-2; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if(arr[i][j]!=0)
			{
				int b = i;
				while(b>0)
				{
					b--;
					if(arr[b][j]!=0) break;
				}
				if(arr[b][j]!=0)
				{
					if(arr[b][j]==arr[i][j]&&c[b][j]==0)
					{
						arr[b][j] = arr[b][j]*2;
						arr[i][j] = 0;
						}
					}
				}
				else
				{
					arr[b-1][j] = arr[i][j];
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = 0;
		}
	}
}

void up(int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(arr[i][j]!=0)
			{
				int b = i;
				while(b>0)
				{
					b--;
					if(arr[b][j]!=0) break;
				}
				if(arr[b][j]!=0)
				{
					if(arr[b][j]==arr[i][j]&&c[b][j]==0)
					{
						arr[b][j] = arr[b][j]*2;
						arr[i][j] = 0;
						c[b][j]=1;
						if(mx<arr[b][j]){
							mx = arr[b][j];
							cnt++;
						}
					}
					else
					{
						if(b+1==i)
						{
							continue;	
						}
						else
						{
							arr[b+1][j] = arr[i][j];
							arr[i][j] = 0;
						}
					}
				}
				else
				{
					arr[b+1][j] = arr[i][j];
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			c[i][j] = 0;
		}
	}
}
void reset(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tmp[i][j] = arr[i][j];
		}
	}
}

void move(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ans[i][j] = tmp[i][j];
		}
	}
}
void remove(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = ans[i][j];
		}
	}
}

int dfs()
{
	move(n);
	for (int i = 0; i < count; ++i)
	{
		rmove(n);
		up(n);
		reset(n)
		dfs(n);  
	}
}

int main()
{
	int n,a;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>a;
			tmp[i][j] = a;
		}
	}
	reset(n);

}