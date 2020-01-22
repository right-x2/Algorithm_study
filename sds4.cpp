#include <iostream>
#include <vector>

using namespace std;

long long q[200001];
long long v[200001];
long long sum = 0;
long long cnt = 1;
void check_line(long long n)
{
    long long vcnt = 0;
    long long rcnt = 0;
    long long zflag = 0;
    long long idx = 0;
    long long ms = 0;
    for (int i = 0; i < n; ++i)
    {
        if(v[n]==1) ms++;
        else break;
    }
    for (long long i = 0; i < n; i++)
    {
        if(v[i]==0)
        {
            //rcnt++;
            q[idx] = i;
            //vcnt=1;
            idx++;
        }
        else if(v[i]==1)
        {
            /*
            if(vcnt==0){
                cnt++;
            }

            if(rcnt>4){

                    cnt = cnt+rcnt-4;
            }
                    
            rcnt = 0;*/
            long long start = 0;
            if(idx>5) start = idx-5;
            for (long long j = start; j < idx; ++j)
            {
                sum = sum + (i - q[j]);
            }
           // zflag = 1;
        }

    }
    /*
    if(zflag==0) cnt = rcnt;
    else cnt = cnt + rcnt;
    */
    for (int i = n-1; i >=0 ; --i)
    {
        if(v[i]==1)
        {
            zflag = 1;
            rcnt = 0;
        }
        else if(zflag==1&&v[i]==0&&rcnt<5)
        {
            rcnt++;
            if(rcnt==5) v[i] = 5;
            else v[i] = 1;  
        }
    }
    int tkn = v[0];
    for (int i = 1; i < n; ++i)
    {
        if(tkn==1)
        {
            if(v[i]!=1)
            {
                //cout<<i<<"\n";
                cnt++;
                tkn = v[i];
            }
        }
        else
        {
            cnt++;
            if(v[i]==1)
            {
                tkn = v[i];
            }
        }
    }
    if(ms!=0) cnt = cnt + ms -1;
}
int main() {
    long long time;
    cin>>time;
    for (long long j = 0; j < time; ++j)
    {
        long long n,num;
        cin>>n;
        for (long long i = 0; i < n; ++i)
        {
            cin>>num;
            v[i] = num;
        }
        check_line(n);
        cout<<"#"<<"";
        cout<<j+1<<" ";
        cout<<sum<<" ";
        cout<<cnt<<" ";
        cout<<"\n"<<"";
        sum = 0;
        cnt = 1;
        for (long long i = 0; i < n; ++i)
        {
            v[i] = 0;
            q[i] = 0;
        }
    }

    return 0;
}