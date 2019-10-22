#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int c;
	cin>>c;
	if(c<6) cout<<c<<"";
	else if(c%8==1) cout<<1;
	else if(c%4==1) cout<<5<<"";
	else if(c%2==1) cout<<3<<"";
	else if(c%4==0)
	{
		int k = c/4;
		if(k%2==0) cout<<2<<"";
		else cout<<4<<"";
	}
	else if(c%4==2)
	{
		int k = c/4;
		if(k%2==0) cout<<2<<"";
		else cout<<4<<"";
	}
}