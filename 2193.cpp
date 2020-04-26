#include <iostream>
using namespace std;

long long arr[91];
int n;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i <=n; ++i)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    
    cout<<arr[n]<<"\n";
    return 0;
}