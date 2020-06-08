#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

vector< pair<char,int> > pv;
vector<int> ans;
string box ="";
string mx="";
string str;
int chk[101];
int mdx = 0;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int idx = 0;
    string temp ="";
    cin>>str;

    for (int i = 0; i < str.length(); ++i)
    {
        pv.push_back(make_pair(str[i],i));
    }
    sort(pv.begin(),pv.end());
    mx = mx + pv[0].first;
    ans.push_back(pv[0].second);
    chk[0] = 1;
    cout<<mx<<"\n";
    for (int i = 1; i < pv.size(); ++i)
    {
        box = mx;
        mx = "";
        for(int j = 1; j < pv.size(); j++)
        {
            idx = i;
            if(chk[j]==0)
            {
                for(int k = 0; k < ans.size(); k++)
                {
                    if(pv[j].second<ans[k])
                    {
                        idx = k;
                        break;
                    }
                }
                temp = box.substr(0,idx) + pv[j].first+ box.substr(idx,box.length()-idx);
                if(mx==""||mx>temp) 
                {
                   mx = temp;
                   mdx = j; 
                }
               // cout<<temp<<" tp\n";
            }
        }
     //   cout<<mdx<<"\n";
        chk[mdx] = 1;
        ans.push_back(pv[mdx].second);
        sort(ans.begin(),ans.end());
        cout<<mx<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}