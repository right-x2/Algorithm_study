#include <iostream>
#include <algorithm>
#include <vector>

 
using namespace std;
long long mn = 1000000;
int arr[1001][3];


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,r,g,b;
    vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
       cin>>r>>g>>b;
       if(i==0)
       {
            arr[0][0] = r;
            arr[0][1] = g;
            arr[0][2] = b;
       }
       else
       {
            if(arr[i-1][1]>arr[i-1][2]) arr[i][0] = arr[i-1][2] + r;
            else arr[i][0] = arr[i-1][1] + r;
            if(arr[i-1][0]>arr[i-1][2]) arr[i][1] = arr[i-1][2] + g;
            else arr[i][1] = arr[i-1][0] + g;

            if(arr[i-1][0]>arr[i-1][1]) arr[i][2] = arr[i-1][1] + b;
            else arr[i][2] = arr[i-1][0] + b;
       }
    }
    for (int i = 0; i < 3; ++i)
    {
        v.push_back(arr[n-1][i]);
    }
    sort(v.begin(),v.end());
    cout<<v[0]<<"\n";
    
    return 0;
}  