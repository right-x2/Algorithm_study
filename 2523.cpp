#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 0; j < i; ++j)
    	{
    		cout<<"*"<"";
    	}
    	cout<<"\n"<"";
    }
    for (int i = n-1; i >=0; i--)
    {
    	for (int j = 0; j < i; ++j)
    	{
    		cout<<"*"<"";
    	}
    	cout<<"\n"<"";
    }
    return 0;
}  