#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int tc,n,m,a;
    int max = -1;
    cin>>tc;
    for (int i = 0; i < tc; ++i)
    {
        cin>>n>>m;
        for (int j = 0; j < n; ++j)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for (int k = 0; k <v.size() ; ++k)
        {
            if(v[k]*2<=m&&v[k]*2>max) max = v[k]*2;
            else if(v[k]*2>m) break;
            for (int l = k; l < v.size(); ++l)
            {
                if(v[k]+v[l]<=m&&v[k]+v[l]>max) max = v[l]+v[k];
                else if(v[k]+v[l]>m) break;
            }
        }  
        cout<<max<<"\n";
        max = -1;
        v.clear();
    }
}