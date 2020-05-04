#include <iostream>
#include <queue>
using namespace std;

int arr[46];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    arr[0] = 0;
    arr[1] = 1;
    cin>>n;
    for (int i = 2; i <= n; ++i)
    {
    	arr[i] = arr[i-1]+ arr[i-2];
    }
    cout<<arr[n]<<"\n";
	return 0;
}