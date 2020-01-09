#include <iostream>

using namespace std;

int arr[1000001];

int chk(int a)
{
    int mid = 1000000/a;
    for (int i = 2; i <= mid; ++i)
    {
        if(arr[a*i]==0)arr[a*i] = 1;
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int cnt = 0;
    int n,a=1,b;
    arr[1] = 1;
    

    for (int i = 2; i <500001; ++i)
    {
        chk(i);
    }
    while(a!=0)
    {
        cin>>a;
        if(a==0) break;
        
        for (int i = a+1; i <= 2*a; ++i)
        {
        
            if(arr[i]==0){
               cnt++;
            }
        }
        cout<<cnt<<"\n";
        cnt = 0;
    }
    return 0;
    
}  