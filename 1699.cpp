#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int arr[321][100001];
int n;
int ans;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        if(i*i>n) break;
        for (int j = 1; j <= n; ++j)
        {
            if(i*i>j) arr[i][j] = arr[i-1][j];
            else if(j%(i*i)==0) 
            {
                if(arr[i-1][j]==0) arr[i][j] = j/(i*i);
                else arr[i][j] = min(arr[i-1][j],j/(i*i));
            }
            else if(arr[i-1][j%(i*i)]!=0) 
            {
                if(arr[i-1][j]==0) arr[i][j] = j/(i*i) + arr[i-1][j%(i*i)];
                else arr[i][j] = min(arr[i-1][j],j/(i*i) + arr[i-1][j%(i*i)]);
            }
            else
            {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    ans = n;
    for (int i = 1; i <= 320; ++i)
    {
        if(arr[i][n]==0) continue;
        else if (ans > arr[i][n]) ans = arr[i][n];
    }
    cout<<ans<<"\n";
    return 0;
}  