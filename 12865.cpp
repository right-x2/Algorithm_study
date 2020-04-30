#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][100001];
int n,m;
vector< pair<int,int> >pv;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        pv.push_back(make_pair(a,b));
    }
    sort(pv.begin(),pv.end());
    for (int i = 1; i <=pv.size(); ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if(j<pv[i-1].first)arr[i][j] = arr[i-1][j];
            else
            {
                arr[i][j] = max(pv[i-1].second+arr[i-1][j-pv[i-1].first],arr[i-1][j]);
            }
        }
    }
    cout<<arr[n][m]<<"\n";
    return 0;
}