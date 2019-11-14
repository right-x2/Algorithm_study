#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{

	int a, b, g;
	int v, max , d;
	cin>>a>>b>>v;
	g = a-b;
	max = v - a;
	d = max/g;
	if(d*g<max) d = d +2;
	else d= d+1;
	cout<<d<<"\n";
}
