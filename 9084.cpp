#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int arr[21][100001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,num,t;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>n;
        for (int j = 0; j < n; ++j)
        {
            cin>>num;
            v.push_back(num);
        }
        cin>>m;     
        for (int j = 0; j < v.size(); ++j)
        {
            for (int k = 1; k <= m; ++k)
            {
                if(k<v[j]) arr[j+1][k] = arr[j][k];
                else if(k==v[j]) arr[j+1][k] = arr[j][k] + 1;
                else arr[j+1][k] = arr[j][k] + arr[j+1][k-v[j]] ;
            }
        }
        cout<<arr[v.size()][m]<<"\n";
        for (int j = 0; j <= v.size(); ++j)
        {
            for (int k = 0; k <= m; ++k)
            {
                arr[j][k] = 0;
            }
        }
        v.clear();
    }
    return 0;
}  