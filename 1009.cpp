#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
vector<int> v;
int main(void)
{
	int t, a, b, answer;
	int sum = 1;
	int flag = 0;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>a>>b;
		
		if(b==0)
		{
			if(i==t-1)cout<<1<<"";
			else cout<<1<<"\n";
			continue;
		}
		else if(a>=10) 
		{
			if(a%10==0)
			{
				if(i==t-1)cout<<10<<"";
				else cout<<10<<"\n";
				continue;
			}
			else
			{
				a = a%10;
			}
		}
		sum = sum * a;
		v.push_back(sum);
		while(flag==0)
		{
			sum = sum * a;
			if(sum==10 || sum%10==0) sum = 10;
			else if(sum>10) sum = sum%10;
			for (int k = 0; k < v.size(); ++k)
			{
				if(v[k]==sum)
				{
					flag = 1;
					break;
				} 
			}
			if(flag == 0) v.push_back(sum);
		}
		if(b<v.size()) answer = b - 1;
		else
		{
			answer = b%v.size();
			if(answer==0) answer = v.size()-1;
			else answer = answer + -1;
		}
		if(i<t-1)cout<<v[answer]<<"\n";
		else cout<<v[answer]<<"";
		sum = 1;
		answer = 0;
		flag=0;
		v.erase(v.begin(),v.begin()+v.size());
	}
}