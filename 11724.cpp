#include <iostream>
#include <vector>


using namespace std;

vector<int> v[1001];
int cnt;
int arr[1001][1001];
int check(int a)
{
	int cc = 0;
	if(v[a].size()==0) return 1;
	for(int i = 0; i < v[a].size(); i++)
	{
		if(arr[a][v[a][i]]==0)
		{
			cc++;
			arr[a][v[a][i]]=1;
			arr[v[a][i]][a]=1;
			check(v[a][i]);
		} 
	}
	if(cc!=0) return 1;
	else return 0;
}

int main()
{
	int a,b,n,m;
	cin>>n>>m;
	for (int i = 0; i < m; i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		if(check(i)==1) cnt++;
	}
	cout<<cnt<<"\n";
}
