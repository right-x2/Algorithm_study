#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long arr[41][41];
int chk[41];
int wc[41];
long long cnt;
int n,m,k;

long long dp(int idx, int num)
{
    if(idx==n)
    {
        int ans = 0;
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if(chk[i]==0)
            {
                ans = i;
                cnt++;
            }
        }
        if(cnt==0) return 1;
        else return 0;
    }
    if(arr[idx][num]!=0) return arr[idx][num];
    if(idx+1==num)
    {
        if(wc[num]==1) return 0;
        else
        {
            chk[idx] = 1;
            arr[idx][num] = arr[idx][num] + dp(num,idx);
            chk[idx] = 0;            
        }
    }
    else
    {
        if(wc[idx+1]==1)
        {
            chk[idx+1] = 1;
            arr[idx][num] = arr[idx][num] + dp(idx+1,idx+1);
            chk[idx+1] = 0;             
        }
        else
        {
            chk[idx+1] = 1;
            int a = dp(idx+1,idx+1);
            chk[idx+1] = 0; 

            int b = 0;
            if(idx+2<=n)
            {
                chk[idx+2] = 1;
                b = dp(idx+1,idx+2);
                chk[idx+2] = 0;                 
            }
            arr[idx][num] = arr[idx][num] + a+b;

        }
    }
    return arr[idx][num];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>num;
        wc[num] = 1;
    }
    if(wc[1]==1)
    {
        chk[1] = 1;
        arr[0][0] = arr[0][0]+ dp(1,1);
        chk[1] = 0;
    }
    else
    {
        chk[1] = 1;
        int a = dp(1,1);
        chk[1] = 0;

        int b = 0;
        if(n>1)
        {
            chk[2] = 1;
            b = dp(1,2);
            chk[2] = 0;            
        }
        arr[0][0] = a + b;
    }
    cout<<arr[0][0]<<"\n";
    return 0;
}  