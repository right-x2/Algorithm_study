#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[12];

int solve(int a)
{
	if(a<=0) return 0;
	if(a==1) return 1;
	if(a==2) return 2;
	if(a==3) return 4;

	return solve(a-1)+solve(a-2)+solve(a-3);
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a;
    	cout<<solve(a)<<"\n";
    }
    return 0;
}  