#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int> >v;
int n,m;
int t;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>t;
    for (int i = 0; i < t; ++i)
    {
        cin>>n>>m;
        for (int j = 0; j < n; ++j)
        {
            cin>>num;
            v.push_back(make_pair(num,j));
        }
        int idx = 0;
        int cnt = 1;
        int flag = 0;
        while(1)
        {
            for (int i = idx+1; i < v.size(); ++i)
            {
                if(v[idx].first<v[i].first)
                {
                    v.push_back(make_pair(v[idx].first,v[idx].second));
                    flag = 1;
                    idx++;
                    break;
                }
            }
            if(flag==0)
            {
                if(v[idx].second==m)
                {
                  cout<<cnt<<"\n";
                  break;  
                }
                else cnt++;
                idx++;
            }
            flag = 0;
        }
        v.clear();
    }
    return 0;
}