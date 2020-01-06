#include <iostream>

using namespace std;

int arr[10001];
void dp(int n)
{
    while(n<10000)
    {
        if(n<10)
        {
            n = n + n;
            
            arr[n] = 1;
        }
        else if(n<100)
        {
            n = n+(n/10) + (n%10);
            arr[n] = 1;
        }
        else if(n<1000)
        {
            n = n+(n/100) + ((n%100)/10)+(n%10);
            arr[n] = 1;
        }
        else
        {
            n = n+(n/1000) + ((n%1000)/100) + ((n%100)/10)+(n%10);
            arr[n] = 1;
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for (int i = 1; i < 10001; ++i)
    {
        dp(i);   
    }
    
    for (int i = 1; i < 10001; ++i)
    {
        if(arr[i]!=1) cout<<i<<"\n";
    }
    return 0;
}  