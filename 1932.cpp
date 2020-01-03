#include <iostream>
#include <algorithm>
#include <vector>

 
using namespace std;
int arr[501][501];


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,ans;
    vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
       for (int j = 0; j <i+1 ; ++j)
       {
           cin>>ans;
           if(i==0) arr[0][0] = ans;
           else
           {
             if(j==0) arr[i][0] = arr[i-1][0]+ans;
             else if(j==i) arr[i][j] = arr[i-1][i-1]+ans;
             else
             {
                if(arr[i-1][j-1]>arr[i-1][j]) arr[i][j] = arr[i-1][j-1] + ans;
                else arr[i][j] = arr[i-1][j] + ans;
             }
           }
           
       }
    }
    for (int i = 0; i < n; ++i)
    {
        v.push_back(arr[n-1][i]);
    }
    sort(v.begin(),v.end());
    cout<<v[n-1]<<"\n";
    
    return 0;
}  