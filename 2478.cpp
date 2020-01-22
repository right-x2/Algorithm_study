#include <iostream>

 
using namespace std;

long long arr[100];
void fibo (int n)
{
    int i = 0;
    while(i+2<=n)
    {
        if(arr[i+2]==0)
        {
            arr[i+2] = arr[i] + arr[i+1];
        }
        i++;
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,t;
    arr[0] = 0;
    arr[1] = 1;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>n;
        fibo(n);
        if(n==0) cout<<1<<" ";
        else cout<<arr[n-1]<<" ";
        cout<<arr[n]<<"\n";
    }
    return 0;
}  