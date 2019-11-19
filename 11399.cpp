#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int arr[1001] ={0,};
	int n,a;
	int sum = 0;
	vector<int> v;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	arr[0] = v[0];
	sum = arr[0];
	for (int i = 1; i <n ; ++i)
	{
		arr[i] = arr[i-1] + v[i];
		sum = sum + arr[i];
	}
	cout<<sum<<"\n";
}
