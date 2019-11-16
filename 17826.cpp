#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<int> v;
	int n = 0;
	int a  = 0;
	int cnt = 0;
	for (int i = 0; i < 50; ++i)
	{
		cin>>a;
		v.push_back(a);
	}
	cin>>n;
	for (int i = 0; i < 50; ++i)
	{
		if(n==v[i]) break;
		else
		{
			cnt++;
		}

	}
	if(cnt<5) cout<<"A+"<<"\n";
	else if(cnt<15) cout<<"A0"<<"\n";
	else if(cnt<30) cout<<"B+"<<"\n";
	else if(cnt<35) cout<<"B0"<<"\n";
	else if(cnt<45) cout<<"C+"<<"\n";
	else if(cnt<48) cout<<"C0"<<"\n";
	else cout<<"F"<<"\n";
}
