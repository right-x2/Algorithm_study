#include <iostream>
using namespace std;

int arr[65][65];
int cnt = 0;
string ans="";
int def(int a,int b,int n)
{
    int num = arr[a][b];
    int flag = 0;
    for (int i = a; i < a+n; ++i)
    {
        for (int j = b; j < b+n; ++j)
        {
            if(arr[i][j]!=num)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1) break;
    }
    if(flag==0)
    {
        if (num==1) ans=ans+"1";
        else ans = ans +"0";
    }
    else if(n==1)
    {
        if (num==1) ans=ans+"1";
        else ans = ans +"0";
    }
    else
    {
        ans = ans+"(";
        def(a,b,n/2);
        def(a,b+n/2,n/2);
        def(a+n/2,b,n/2);
        def(a+n/2,b+n/2,n/2);
        ans = ans+")";
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    string str;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < n; ++j)
        {
            if(str[j]=='1') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    def(0,0,n);
    cout<<ans<<"\n";
} 