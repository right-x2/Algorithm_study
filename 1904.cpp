#include <iostream>

 
using namespace std;
int arr[1000000001];

int dp(int n,long long cnt)
{
    if(n<=1) return 0;
    if(n%3==0)
    {
        if(arr[n/3]==0||arr[n/3]>cnt+1)
        {
            arr[n/3]=cnt+1;
            dp(n/3,cnt+1);
        }
        if(arr[(n-1)/2]==0||arr[(n-1)/2]>cnt+2)
        {
            arr[(n-1)/2]=cnt+2;
            dp((n-1)/2,cnt+2);
        }
    }
    else if(n%2==0)
    {
        if(arr[n/2]==0||arr[n/2]>cnt+1)
        {
            arr[n/2]=cnt+1;
            dp(n/2,cnt+1);
        }
        if(arr[(n-1)/3]==0||arr[(n-1)/3]>cnt+2)
        {
            arr[(n-1)/3]=cnt+2;
            dp((n-1)/3,cnt+2);
        }
    }
    else
    {
        if(arr[n-1]==0||arr[n-1]>cnt+1)
        {
            arr[n-1]=cnt+1;
            dp(n-1,cnt+1);
        }
    }
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    dp(n,0);
    cout<<arr[1]<<"\n";
    return 0;
}  