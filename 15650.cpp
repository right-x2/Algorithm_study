#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bfs(vector<int> v, int n,int s,int m)
{
	if(v.size()==m) 
	{
		for (int i = 0; i < m; ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<""<<"\n";
		return 0;
	}
	//cout<<"ada"<<"\n";
	for (int i = s; i <= n; ++i)
	{

		v.push_back(i);
		bfs(v,n,i+1,m);
		v.pop_back();

	}
	return 0;
}

int main()
{
	vector<int> v;
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <=n-m+1 ; ++i)
	{
		v.push_back(i);
		bfs(v,n,i+1,m);
		v.pop_back();
	}
}
