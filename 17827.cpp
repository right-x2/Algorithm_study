#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int,int> > v;

int node(int a, int n, int k)
{
	int ans = v[0].first;
	int head = 1;
	if(a>n)
	{
		head = (a-n)%(n-k+1);
		head = head + k-1;
		ans = v[head].first;
	}
	else
	{
		for (int i = 0; i <a; ++i)
		{
			ans = v[head].first;
			head = v[head].second;
		}
	}
	return ans;
}
int main()
{
	
	int a;
	int n,m,k;
	int temp,last,head;
	cin>>n>>m>>k;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>a;
		v.push_back(make_pair(a,i+1));
	}
	cin>>a;
	v.push_back(make_pair(a,k-1));
	for (int i = 0; i < m; ++i)
	{
		cin>>a;
		cout<<node(a,n,k)<<"\n";
	}
}
