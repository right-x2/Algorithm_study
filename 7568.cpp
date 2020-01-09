#include <iostream>
#include <vector>

using namespace std;

vector< pair<int,int> > pv;
vector<int> v;
int mx,m;
int arr[51];


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,b,cnt = 0,rank=0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        pv.push_back(make_pair(a,b));
    }
    for (int i = 0; i < pv.size(); ++i)
    {
        for (int j = 0; j < pv.size(); ++j)
        {
            if((pv[i].first<pv[j].first)&&(pv[i].second<pv[j].second))
            {
                cnt++;
            }
        }
        v.push_back(cnt+1);
        cnt = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}  