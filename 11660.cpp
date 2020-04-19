#include <iostream>

using namespace std;

long long arr[1025][1025];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,k;
    int a,b,c,d;
    cin>>n>>m;
    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 1; j <= n; ++j)
    	{
            cin>>k;
    		if(i==1&&j==1) arr[i][j] = k;
            else if(i==1){
                arr[i][j] = arr[i][j-1] + k;
            } else if(j==1){
                arr[i][j] = arr[i-1][j] + k;
            } else{
                arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + k;
            }
    	}
    }
    for (int i = 0; i < m; ++i)
    {
    	cin>>b>>a>>d>>c;

        long long sum = arr[d][c] - arr[d][a-1] - arr[b-1][c] + arr[b-1][a-1];
        cout<<sum<<"\n";

    }
    return 0;
}  