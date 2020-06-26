#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[10001];
int n;
string ans;


int lft(int num)
{
    int mod;
    if(num>999)
    {
        mod = 1000;
    }
    else return num*10;

    int k = num/mod;
    int tmp = num%mod;
    tmp = tmp * 10 + k;
    return tmp;
}

int rit(int num)
{
    int k = (num%10)*1000;

    int tmp = (num/10)+k;

    return tmp;
}

int solve(int a, int b)
{
    queue< pair<int,string> >q;
    q.push(make_pair(a,""));
    arr[a] = 1;
    while(!q.empty())
    {
        int tmp;
        int m = q.front().first;
        string str = q.front().second;
        q.pop();
        if(m==b)
        {
            ans = str;
            return 0;
        }

        if(arr[(m*2)%10000]==0)
        {
            arr[(m*2)%10000] = 1;
            q.push(make_pair((m*2)%10000,str+"D"));
        }

        if(m>0&&arr[m-1]==0)
        {
            arr[m-1] = 1;
            q.push(make_pair(m-1,str+"S"));            
        }
        else if(m==0&&arr[9999]==0)
        {
            arr[9999] = 1;
            q.push(make_pair(9999,str+"S"));             
        }

        tmp = lft(m);

        if(arr[tmp]==0)
        {
            arr[tmp] = 1;
            q.push(make_pair(tmp,str+"L"));
        }

        tmp = rit(m);

        if(arr[tmp]==0)
        {
            arr[tmp] = 1;
            q.push(make_pair(tmp,str+"R"));            
        }
    }
    return 0;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        solve(a,b);
        cout<<ans<<"\n";
        ans = "";
        for (int i = 0; i <= 10000; ++i)
        {
            arr[i] = 0;
        }
    }

    
    return 0;
}