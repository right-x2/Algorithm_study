#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main()
{
	int arr[5001] = {0,};
	int n,k,m;
	int a = 0;
	int cnt  = 0;
	int max = 0;
	int t = 0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if (a>max) max = a;
		v.push_back(a);
	}
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		cin>>m;
		t = v[m-1];
		v.erase((v.begin()+m-1));
		for (int j = 0; j < v.size(); ++j)
		{
			if(t>=arr[v[j]]) arr[v[j]]++;
		}
		for (int j = 0; j <=max; ++j)
		{
			if((arr[j]%2==0)&& arr[j]!=0) cnt++;
		}
		cout<<n-cnt-1<<"\n";

		cnt = 0;
		v.push_back(t);
	}

}
