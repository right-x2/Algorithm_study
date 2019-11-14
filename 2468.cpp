#include <iostream>
#include <vector>


using namespace std;

int arr[101][101];
int c[101][101];
int x[4] = {1,-1,0,0};
int y[4] = {0,0,-1,1};
int bfs(int cy,int cx,int n, int a)
{
	if(c[cy][cx] == 1) return 0;
	else c[cy][cx] = 1;
	for(int i = 0; i < 4 ; i++)
	{
		if(cx+x[i]<n&&cx+x[i]>=0&&cy+y[i]<n&&cy+y[i]>=0)
		{
			if(arr[cy+y[i]][cx+x[i]]>a&&c[cy+y[i]][cx+x[i]]==0)
			{
				bfs(cy+y[i],cx+x[i], n, a);
			}
		}
	}



	return 1;
}

int main()
{
	int a,b,n,m,cnt=0;
	cin>>n;
	int max = 1;
	m = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>a;
			if(m<a) m = a;
			arr[i][j] = a;
		}
	}
	for(int i = 1; i <= m; i++)
	{	

		for (int j = 0; j <n; ++j)
		{

			for (int k = 0; k <n; ++k)
			{
				if(arr[j][k]>i&&c[j][k]==0)
				{
					cnt++;
					bfs(j,k,n,i);
				}
			}
		}
		for (int j = 0; j <n; ++j)
		{
			for (int k = 0; k <n; ++k)
			{
				c[j][k] = 0;/* code */
			}
		}
		if(cnt>max) max = cnt;
		cnt = 0;
	}
	cout<<max<<"\n";
}
