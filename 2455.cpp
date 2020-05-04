#include <iostream>
#include <vector>
using namespace std;

int n,m;
int arr[5];
int mx = 0;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for (int i = 1; i <= 4; ++i)
    {
        cin>>n>>m;
        arr[i] = m-n+arr[i-1];
        if(arr[i]>mx) mx = arr[i];
    }
    cout<<mx<<"\n";
    return 0;
}