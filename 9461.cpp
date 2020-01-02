#include <iostream>

 
using namespace std;

long long arr[1001];
void tile (int n)
{
    int i = 7;
    if(n>6)
    {
        while(i<=n)
        {
            if(arr[i]==0) arr[i] = arr[i-5]+arr[i-1];
            i++;
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,t;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    arr[6] = 3;
    arr[7] = 4;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>n;
        tile(n);
        cout<<arr[n]<<"\n";
    }
    
    
    return 0;
}  