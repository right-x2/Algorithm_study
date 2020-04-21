#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[51][51];
int n,m,len;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a;
    int flag = 0;
    cin>>n>>m;
    string str;

    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < m; ++j)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    if(n>m) len = m;
    else len = n;

    for (int i = len-1; i > 0; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {
                if(j+i<n&&k+i<m)
                {
                    if(arr[j][k]==arr[j+i][k]&&arr[j][k]==arr[j][k+i]&&arr[j][k]==arr[j+i][k+i]){
                        cout<<(i+1)*(i+1)<<"\n";
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag==1) break;
        }
        if (flag==1) break;
    }
    if(flag==0) cout<<1<<"\n";
    return 0;
}  