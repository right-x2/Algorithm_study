#include <iostream>
using namespace std;

int arr[5000][5000];
int mcnt = 0;
int zcnt = 0;
int pcnt = 0;
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
        if (num==1) pcnt++;
        else if(num==0) zcnt++;
        else mcnt++;
    }
    else if(n==1)
    {
        if (num==1) pcnt++;
        else if(num==0) zcnt++;
        else mcnt++;
    }
    else
    {
        def(a,b,n/3);
        def(a,b+n/3,n/3);
        def(a,b+(n*2)/3,n/3);
        def(a+n/3,b,n/3);
        def(a+n/3,b+n/3,n/3);
        def(a+n/3,b+(n*2)/3,n/3);
        def(a+(2*n)/3,b,n/3);
        def(a+(2*n)/3,b+n/3,n/3);
        def(a+(2*n)/3,b+(n*2)/3,n/3);
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
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
        }
    }
    def(0,0,n);
    cout<<mcnt<<"\n";
    cout<<zcnt<<"\n";
    cout<<pcnt<<"\n";
} 