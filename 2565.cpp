#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

vector< pair<int,int> >v;
vector< pair<int,int> >tmp;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,b;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    tmp.push_back(make_pair(v[0].first,v[0].second));
    for (int i = 1; i < n; ++i)
    {
        int sz = tmp.size()-1;
        if(sz==0)
        {
            if(tmp[sz].second<v[i].second) tmp.push_back(make_pair(v[i].first,v[i].second));
            else
            {
                tmp[sz].first = v[i].first;
                tmp[sz].second = v[i].second;
            }        
        }
        else
        {
            if(tmp[sz].second<v[i].second) tmp.push_back(make_pair(v[i].first,v[i].second));
            else
            {
                for (int j = tmp.size()-2; j >=0 ; --j)
                {
                    if(v[i].second>tmp[j].second)
                    {
                        tmp[j+1].second = v[i].second;
                        tmp[j+1].first = v[i].first;
                        break;
                    }
                }
                if(v[i].second<tmp[0].second) 
                {
                    tmp[0].first = v[i].first;
                    tmp[0].second = v[i].second;
                }
            }
        }
    }
    cout<<n-tmp.size()<<"\n";
}  