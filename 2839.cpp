#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long n,cnt,temp,flag = 0;
    cin>>n;
    if(n%5==0) cout<<n/5<<"\n";
    else if(n%5==3)
    {
        cout<<(n/5)+1<<"\n";
    }
    else
    {
        cnt = n/5;
        cnt--;
        while(cnt>0)
        {
            temp = n - (5*cnt);
            if(temp%3==0)
            {
                cout<<temp/3+cnt<<"\n";
                flag = 1;
                break;
            }
            cnt--;
        }
        if(flag == 0)
        {
            if(n%3==0) cout<<n/3<<"\n";
            else cout<<-1<<"\n";   
        }
    }
    return 0;
}  