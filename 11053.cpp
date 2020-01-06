#include <iostream>

using namespace std;
int arr[1001];
int ck[1001];
int mx = 0;
int dp(int i, int n)
{
    int max = 0;
    int min = arr[i];
    int cnt;
    if(ck[i]==0) cnt = 1;
    else cnt = ck[i];
    if(ck[i]>mx) mx = ck[i];
    for (int j = i+1; j < n; ++j)
    {
        if(min<arr[j])
        {
            if(ck[j]>cnt+1) return 0;
            else
            {
                min = arr[j];
                cnt = cnt + 1;
                ck[j] = cnt;
                if(mx<cnt) mx = cnt;
            }
        }
        else
        {
            for (int k = j-2; k >=0; --k)
            {
                if(arr[j]>arr[k])
                {
                    if(max<ck[k]) 
                    {
                       max = ck[k];
                    }

                }
            }
            ck[j] = max + 1;
            max = 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    ck[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        dp(i,n);
    }
    
    cout<<mx<<"\n";
    return 0;
}  