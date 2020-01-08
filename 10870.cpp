#include <iostream>

using namespace std;

int fibo(int n)
{
    if(n==0) return 0;
    else if(n==2) return 1;
    else if(n==1) return 1;
    return fibo(n-1)+fibo(n-2);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    cout<<fibo(n)<<"\n";

    return 0;
    
}  