#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int n,k,rota;
string str;
string ans;
vector<string> v;
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
        cin>>n>>k;
        cin>>str;
        rota = n/4;
        
        for(int i = 0; i < rota; i++)
        {
            int flag = 0;
            for (int j = 0; j < v.size(); ++j)
            {
                if(v[i]==str.substr(i,rota))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0) v.push_back(str.substr(i,rota));
            flag = 0;
            
            for (int j = 0; j < v.size(); ++j)
            {
                if(v[i]==str.substr(i+rota,rota))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0) v.push_back(str.substr(i+rota,rota));
            flag = 0;

            for (int j = 0; j < v.size(); ++j)
            {
                if(v[i]==str.substr(i+(rota*2),rota))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0) v.push_back(str.substr(i+(rota*2),rota));
            flag = 0;


            string temp = str.substr(i+(rota*3),rota) + str.substr(0,i);
            for (int j = 0; j < v.size(); ++j)
            {
                if(v[i]==temp)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0) v.push_back(temp);
            flag = 0;
        }
        
        sort(v.begin(),v.end());
        ans = v[v.size()-k];
        long long answer = 0;
        long long mul = 1;
        for (int i = ans.length()-1; i >= 0; i--)
        {
            if(ans[i]>='A')
            {
                answer = answer + ((ans[i]-'A')+10)*mul;
            }
            else
            {
                answer = answer + (ans[i]-'0')*mul;
            }
            mul = mul * 16;
        }
        cout<<"#"<<test_case<<" "<<answer<<"\n";
        v.clear();
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}