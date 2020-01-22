#include <iostream>

 
using namespace std;
int arr[10001];


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,ans,cnt = 0,temp;
    cin>>n;
    for (int i = 0; i <= n; ++i)
    {
        
        if(i==0) arr[0] = 0;
        else if (i==1)
        {
            cin>>ans;
            arr[1] = ans;
            cnt++;
        }
        else
        {
            cin>>ans;
            if(cnt==2)
            {
                
                if(i>3&&arr[i-3] + ans < arr[i-4] + ans) temp = temp + arr[i-4] + ans;
                else temp = temp + arr[i-3] + ans;
                arr[i] = arr[i-2] + ans;
                if(temp > arr[i])
                {
                    cnt = 2;
                    arr[i] = temp;
                }
                else
                {
                   cnt = 1; 
                }
                temp = ans;
                
            }
            else
            {

                if(arr[i-1]>arr[i-2])
                {
                    arr[i] = arr[i-1] + ans;
                    cnt++;
                    temp = ans;
                }
                else
                {
                    arr[i] = arr[i-2] + ans;
                    cnt = 1;
                    temp = ans;
                }
            }
            //cout<<i<<" "<<arr[i]<<"\n";
        }
    }
    int max = arr[n];
    if(max<arr[n-1]) max = arr[n-1];
    cout<<max<<"\n";
    
    return 0;
}  