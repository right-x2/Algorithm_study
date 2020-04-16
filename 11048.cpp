#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
int chk[1001][1001];
int n,m;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cin>>arr[i][j];
    		if(i==0&&j==0) chk[i][j] = arr[i][j];
    		else if(i==0)
    		{
    			chk[i][j] = chk[i][j-1];
    			chk[i][j] = chk[i][j] + arr[i][j];
    		}
    		else if(j==0)
    		{
				chk[i][j] = chk[i-1][j];
				chk[i][j] = chk[i][j] + arr[i][j];
    		} 
    		else
    		{
    			chk[i][j] = max(chk[i][j-1],chk[i-1][j]);
    			chk[i][j] = chk[i][j] + arr[i][j];
    		}
    	}
    }

    cout<<chk[n-1][m-1];
	return 0;
}