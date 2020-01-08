#include <iostream>

using namespace std;

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
    if(cnt==0) return 1;
    else return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int cnt = 0;
    int n,a;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        if(chk(a))cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
    
}  