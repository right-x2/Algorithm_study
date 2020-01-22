#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int cnt;
	char ak ;
	string str;
	string ans = "";
	long long sum = 0;
	vector<long long> v;
	cin>>str;
	for (int i = 0; i < str.length(); ++i)
	{
		if(str[i]=='0')  cnt++;
		else
		{
			sum = sum + (str[i]-'0');
		}
		v.push_back(str[i]-'0');
	}
	if(cnt != 0 && sum%3==0) 
	{
		sort(v.begin(),v.end());
		int len = v.size();
		for (int i = 0; i < len; ++i)
		{
			ak  = v[len-1-i]+'0';
			ans = ans +  ak;
		}
		cout<<ans<<"";
	}
	else cout<<-1<<"\n";
}
