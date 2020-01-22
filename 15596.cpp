#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n = 1;
    while(n<10000)
    {
        if(n<10)
        {
            n = n + n;
            arr[n] = 1;
        }
        else(n<100)
        {
            n = n+(n/10) + (n%10);
            arr[n] = 1;
        }
        else(n<1000)
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
    for (int i = 0; i < 10001; ++i)
    {
        if(arr[i]==0) cout<<i<<"\n";
    }
    return 0;
}  