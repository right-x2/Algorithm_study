#include <iostream>

using namespace std;
int arr[15][15];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,b,c,ans,flag = 0,cnt = 0,rc = 0,mid;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        ans = (b-a)/2;
        mid = b-a;
        c = 0;
        while(c<mid)
        {
            rc++;
            if(c>=ans&&flag ==0)
            {
                mid = b-a-c;
                c=0;
                cnt=0;
                flag =1;
            }
            cnt++;
            c = c + cnt;
        }
        if(b-a==1||b-a==2||b-a==3)cout<<b-a<<"\n";
        else
        {
            cout<<rc<<"\n";
        }
        cnt = 0;
        flag = 0;
        rc = 0;
    }
    return 0;
    
}  