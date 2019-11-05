#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
    
    vector<pair<int,int> > v;
    int len = food_times.size();
    int idx = 0;
    int count = 0;
    int max = len;
    int answer = 0;
    for(int i = 0; i < food_times.size();i++)
    {
        v.push_back(make_pair(food_times[i],i));
    }
    for(int i = 0; i <k; i ++)
    {
        if(len==0) return -1;
            else
            {
                v[idx].first = v[idx].first - 1;
                if(v[idx].first==0)
                {
                    
                    v.erase(v.begin()+idx);
                    len = len - 1;
                    if(idx == len) idx = 0;
                }
                else
                {
                    idx++;
                    if(idx == len) idx = 0;
                }
            }
    }
    answer = v[idx].second + 1;
    return answer; 
}

int main()
{
    vector<int> v;
    int a;
    for(int i = 0; i < 4; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    cout<<solution( v , 23)<<"\n";
}