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
    int n,k,a,b,sum = 0,answer = 0;
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    if(v[0].first<=k)
    {
        tmp.push_back(make_pair(v[0].first,v[0].second));
        sum = v[0].first;
        for (int i = 1; i < n; ++i)
        {
            int sz = tmp.size()-1;
            int rsum = 0;
            int point = 0;
            int cnt = 0;
            if(sum+v[i].first<=k)
            {
                if(v[i].first==tmp[sz].first)
                {
                    if(v[i].second>tmp[sz].second)
                    {
                        tmp.pop_back();
                        tmp.push_back(make_pair(v[i].first,v[i].second));
                        sum = sum - tmp[sz].second + v[i].second;
                    }
                }
                else
                {
                    tmp.push_back(make_pair(v[i].first,v[i].second));
                    sum = sum + v[i].first;
                }
            }
            else
            {
                
                while(sz>=0)
                {
                    rsum = rsum + tmp[sz].first;
                    point = point + tmp[sz].second;
                    cnt++;
                    cout<<v[i].first<<" dd";
                    cout<<tmp[sz].first<<" dd\n";
                    if(rsum>=v[i].first)
                    {
                        
                        if(point<=v[i].second)
                        {

                            for (int j = 0; j < cnt; ++j)
                            {
                                tmp.pop_back();
                            }
                            tmp.push_back(make_pair(v[i].first,v[i].second));
                            
                        }
                        break;
                    }
                    else if(sum-rsum+v[i].first<=k)
                    {
                        if(v[i].second>point)
                        {
                            for (int j = 0; j < cnt; ++j)
                            {
                                tmp.pop_back();
                            }
                            tmp.push_back(make_pair(v[i].first,v[i].second));
                            break;                            
                        }
                    }
                    sz--;
                }
            }
        }
        for (int i = 0; i < tmp.size(); ++i)
        {
            cout<<tmp[i].second<<"\n";
            answer = answer + tmp[i].second;
        }
        cout<<answer<<"\n";
    }
    else cout<<0<<"\n";
}  