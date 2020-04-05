#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>


using namespace std;

int n;
int arr[1001];
int check[1001];
int solve()
{
	stack<int> stk;
	stk.push(0);
	while(!stk.empty())
	{
		int k = stk.top();
		stk.pop();
		for (int i = 1; i <= arr[k]; ++i)
		{
			if((check[k+i]==0||check[k+i]>check[k] + 1)&&k+i<n)
			{
				stk.push(k+i);
				check[k+i] = check[k] + 1;
			}
		}
	}
	if(check[n-1]==0&&n-1!=0) return -1;
	else return check[n-1];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;	
    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    }
    cout<<solve()<<"\n";
    return 0;
    
}  