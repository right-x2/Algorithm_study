#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
    	for (int j = i; j <= n; ++j)
    	{
    		cout<<"*"<<"";
    	}
    	if(i<n)cout<<"\n"<<"";
    }
	return 0;
}