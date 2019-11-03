#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{	
	int a, b;
	int t, n, s, m;
	cin>>t;
	
	for (int i = 0; i < t; ++i)
	{
		vector<pair<int, int> > v;
		cin>>n;
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			cin>>s>>m;
			v.push_back(make_pair(s,m));
		}
		sort(v.begin(),v.end());
		a = v[0].first;
		b = v[0].second;
		int c = v[0].first;
		int d = v[0].second;
		for (int j = 1; j < n; ++j)
		{
			if((v[j].first>a && v[j].second>b) || (v[j].first>c && v[j].second>d)) cnt++;
			if(v[j].second<d)
			{
				c =  v[j].first;
				d = v[j].second;
			}
		}
		cout<<n-cnt<<"\n";
	}
}