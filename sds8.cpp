#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

vector< pair<int, int> > pv;
//vector< vector<int> > arr;
int minx = 100000;

int dfs(int cnt ,int sum,int n,int idx,int k)
{
	//cout<<idx<<" ";
	//cout<<cnt<<" ";
	//cout<<sum<<"\n";
	if(cnt>k) return 0;
	if(idx==n){
		
		if(minx>sum) minx = sum;
		return 0;
	}
	for (int i = idx; i < idx+k-cnt+1; ++i)
	{
		if(i+1>n) break;
		else
		{
			dfs(i-idx+cnt,sum+abs(pv[idx].first-pv[i+1].first)+abs(pv[idx].second-pv[i+1].second),n,i+1,k);
		}
	}
}

int main()
{
	int n,k,a,b;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		pv.push_back(make_pair(a,b));
	}
	for (int i = 0; i < k+1; ++i)
	{
		if(i+1>n-1) break;
		dfs(i,abs(pv[0].first-pv[i+1].first)+abs(pv[0].second-pv[i+1].second),n-1,i+1,k); 
	}
	cout<<minx<<"\n";
	minx = 100000;
	pv.clear();
}