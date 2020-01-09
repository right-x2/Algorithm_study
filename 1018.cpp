#include <iostream>
#include <vector>

using namespace std;


char arr[51][51];
int mn=2501;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,cnt,a,b;
    char pre;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
        }
    }
    for (int k = 0; k <= n-8; ++k)
    {
        for (int l = 0; l <= m-8 ; ++l)
        {
            for (int p = 0; p < 2; ++p)
            {
                for (int i = k; i < k+8; ++i)
                {
                    for (int j = l; j < l+8; ++j)
                    {
                        if(i==k&&j==l)
                        {
                            if(p==0) pre = 'W';
                            else pre = 'B';
                        }

                        if(pre==arr[i][j]){
                            cnt++;
                            //cout<<pre<<" gpre ";
                            //cout<<i<<j<<"\n";
                            if(pre=='B')
                            {
                                if(j!=l+7)pre='W';
                            }
                            else
                            {
                                if(j!=l+7)pre='B';
                            }
                        }
                        else
                        {
                           if(j!=l+7) pre = arr[i][j]; 
                           //cout<<pre<<" rpre \n";
                        }
                    }
                }
                //cout<<cnt<<" cntcnt\n";
                if(cnt<mn){
                    mn = cnt;
                    a = k;
                    b = l;
                }
                cnt = 0; 
            }    
        }
    }
    cout<<mn<<"\n";
    return 0;
}  