#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int chk[26];
int arr[26];
vector<string> v;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int sum = 0;
    string str;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        v.push_back(str);
    }
    for (int i = 0; i < v.size(); ++i)
    {
        str = v[i];
        

        for (int j = i+1; j < v.size(); ++j)
        {
            for(int k = 0; k < 26; k++)
            {
                arr[k] = -1;
                chk[k] = 0;
            }
            int flag = 0;
            for(int k = 0; k < str.length(); k++)
            {
                if(arr[str[k]-'a']==-1&&chk[v[j][k]-'a']==0)
                {
                    arr[str[k]-'a'] = v[j][k]-'a';
                    chk[v[j][k]-'a'] = 1;
                }
                else if(arr[str[k]-'a']==v[j][k]-'a'&&chk[v[j][k]-'a'] == 1) continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0) sum++;
        }
    }
    cout<<sum<<"\n";
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}