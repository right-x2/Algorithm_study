#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> v;
int n;
int ans; 


int solve(int idx)
{
    int llen = idx;
    int rlen = n-idx-1;
    int ls = idx-1;
    int rs = idx+1;
    int cnt = 0;
    while(ls>=0&&rs<n)
    {
        if(v[ls]==v[rs])
        {
            ls--;
            rs++;
            continue;
        }
        else
        {
            if(ls>0&&v[ls-1]==v[rs])
            {
                cnt++;
                rlen++;
                ls = ls - 2;
                rs++;
            }
            else if(rs<n-1&&v[rs+1]==v[ls])
            {
                cnt++;
                llen++;
                rs = rs + 2;
                ls--;
            }
            else
            {
                if(llen==rlen)
                {
                    cnt = cnt + 2;
                    llen++;
                    rlen++;
                    rs++;
                    ls--;                    
                }
                else if(llen>rlen)
                {
                    cnt++;
                    rlen++;
                    ls--;
                }
                else
                {
                    cnt++;
                    llen++;
                    rs++;                    
                }

            }
        }
    }

    if(llen>=rlen) cnt = cnt + (llen-rlen);
    else cnt = cnt + (rlen-llen);
    if(cnt<ans) ans = cnt;

    llen = idx+1;
    rlen = n-llen;
    ls = idx;
    rs = idx+1;
    cnt = 0;


    
    while(ls>=0&&rs<n)
    {
        if(v[ls]==v[rs])
        {
            ls--;
            rs++;
            continue;
        }
        else
        {
            if(ls>0&&v[ls-1]==v[rs])
            {
                cnt++;
                rlen++;
                ls = ls - 2;
                rs++;
            }
            else if(rs<n-1&&v[rs+1]==v[ls])
            {
                cnt++;
                llen++;
                rs = rs + 2;
                ls--;
            }
            else
            {
                if(llen==rlen)
                {
                    cnt = cnt + 2;
                    llen++;
                    rlen++;
                    rs++;
                    ls--;                    
                }
                else if(llen>rlen)
                {
                    cnt++;
                    rlen++;
                    ls--;
                }
                else
                {
                    cnt++;
                    llen++;
                    rs++;                    
                }
            }
        }
    }

    if(llen>=rlen) cnt = cnt + (llen-rlen);
    else cnt = cnt + (rlen-llen);
    if(cnt<ans) ans = cnt;

    return 0;
}

int pchk()
{
    if(v.size()%2==0)
    {
        for (int i = 0; i < n/2; ++i)
        {
            if(v[n/2-i-1]!=v[n/2+i])
            {
                return 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < n/2; ++i)
        {
            if(v[n/2-i-1]!=v[n/2+1+i])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    cin>>n;
    
    ans = n-1;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a); 
    }

    if(pchk()==1)
    {
        cout<<0<<"\n";
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        solve(i);
    }

    cout<<ans<<"\n";
    return 0;
}