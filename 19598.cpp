#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> >v;
vector<pair<int,int> >s;
int n;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        int flag=0;
        a = v[i].first;
        b = v[i].second;
        for(int j = 0; j < s.size(); j++)
        {
            if(a>=s[j].second)
            {
                flag = 1;
                s[j].second = b;
                break;
            }
        }
        if(flag==0)
        {
            s.push_back(make_pair(a,b));
        }
    }

    cout<<s.size()<<"\n";
    
    return 0;
}  