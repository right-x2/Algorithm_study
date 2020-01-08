#include <iostream>

using namespace std;

int sum=0;
int mn=10001;

int chk(int a)
{
    if(a==1) return 0;
    int mid = a/2;
    int cnt = 0;
    for (int i = 2; i <= mid; ++i)
    {
        if(a%i==0)
        {
            cnt++;
            break;
        }
    }
    if(cnt==0)
    {
        if(a<mn) mn = a;
        sum = sum +a;
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int cnt = 0;
    int n,a,b;
    cin>>a>>b;
    for (int i = a; i <=b; ++i)
    {
        chk(i);
    }
    if(sum==0) cout<<-1<<"\n";
    else
    {
        cout<<sum<<"\n";
        cout<<mn<<"\n";
    }
    return 0;
    
}  