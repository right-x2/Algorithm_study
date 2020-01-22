#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
     
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
 
            int n,t,d,sz,spot;
            cin>>n;
            vector< pair<int, int> > pv =vector<pair<int, int>>(n, { 0,0 });
            for (int i = 0; i < n; ++i)
            {
                cin>>pv[i].second>>pv[i].first;
            }
            sort(pv.begin(),pv.end());
            spot = pv.back().first-pv.back().second;
            pv.pop_back();
            while(!pv.empty())
            {
                if(spot<pv.back().first)
                {
                    spot = spot-pv.back().second;
                }
                else
                {
                    spot = pv.back().first-pv.back().second;
                }
                pv.pop_back();
            }
            cout<<"#"<<"";
            cout<<test_case<<" ";
            cout<<spot<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}