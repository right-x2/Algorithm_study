#include <iostream>

 
using namespace std;

long long arr[1000001];
void tile (int n)
{
    int i = 1;
    while(i+2<=n)
    {
        arr[i+2] = (arr[i]+arr[i+1])%15746;
        i++;
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    cin>>n;
    tile(n);
    cout<<arr[n]<<"\n";
    return 0;
}  