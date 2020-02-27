#include <iostream>
using namespace std;

int arr[129][129];
int cnt = 0;
int alcnt = 0;
int def(int a,int b,int n)
{
    int flag = 0;
    for (int i = a; i < a+n; ++i)
    {
        for (int j = b; j < b+n; ++j)
        {
            if(arr[i][j]==0)
            {
                flag =1;
                break;
            }
        }
        if(flag==1) break;
    }
    if(flag==0) cnt++;
    else if(n==1) return 0;
    else
    {
        def(a,b,n/2);
        def(a+n/2,b,n/2);
        def(a,b+n/2,n/2);
        def(a+n/2,b+n/2,n/2);
    }
    return 0;
}

int acdef(int a,int b,int n)
{
    int flag = 0;
    for (int i = a; i < a+n; ++i)
    {
        for (int j = b; j < b+n; ++j)
        {
            if(arr[i][j]==1)
            {
                flag =1;
                break;
            }
        }
        if(flag==1) break;
    }
    if(flag==0) alcnt++;
    else if(n==1) return 0;
    else
    {
        acdef(a,b,n/2);
        acdef(a+n/2,b,n/2);
        acdef(a,b+n/2,n/2);
        acdef(a+n/2,b+n/2,n/2);
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }
    def(0,0,n);
    acdef(0,0,n);
    cout<<alcnt<<"\n";
    cout<<cnt<<"\n";
} 