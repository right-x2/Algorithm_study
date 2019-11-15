#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> s;
int main()
{
	int n , a;
	int tot = 0;
	int cnt = 0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		v.push_back(a);

	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		s.push_back(a);
	}
	sort(v.begin(),v.end());
	sort(s.begin(),s.end());
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < s.size(); ++j)
		{
			if(s[j]>v[i])
			{
				cnt++;
				s.erase(s.begin()+j);
				break;
			}
		}
		if(cnt!=0)
		{
			tot++;
		}
		else
		{
			break;
		}
		cnt = 0;
		if(tot>=(n+1)/2) break;
	}

	if(tot>=(n+1)/2) cout<<"YES"<<"\n";
	else
	{
		cout<<"NO"<<"\n";
	}
}
