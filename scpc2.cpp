#include <iostream>

using namespace std;

int arr[100001];

int match(string a, string b)
{
	int cnt = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if(a[i]==b[i]) cnt++;
	}
	return cnt;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m;
    int a,b;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	cin>>arr[i+1];
    	if(i!=0) arr[i+1] = arr[i+1] + arr[i];
    }

    for (int i = 0; i < m; ++i)
    {
    	cin>>a>>b;
    	cout<<arr[b]-arr[a-1]<<"\n";
    }
    return 0;
}  