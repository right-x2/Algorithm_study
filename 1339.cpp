#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[30];
int chk[10];
int achk[30];
int num = 9;
int cnum = 9;
int answer = 0;
vector<string> v;
int len = 0;
int n;

vector<int> s;

int solve()
{
    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int mul = 1;
        for (int j = 0; j < v[i].length()-1; ++j)
        {
            mul = mul * 10;
        }
        for (int j = 0; j < v[i].length(); ++j)
        {

            ans = ans + arr[(v[i][j]-'A')]*mul;
            mul = mul/10;
        }
    } 

    if(ans>answer) answer = ans;  

    return 0;
}

int per(int num, int cnt)
{
    if(cnt==s.size()||num==-1)
    {
        solve();
        return 0;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if(chk[i]==0)
        {
            chk[i] = 1;
            arr[s[i]] = num;
            per(num-1,cnt+1);
            chk[i] = 0;
            arr[s[i]] = 0;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        v.push_back(str);
    }


    for (int j = 0; j < v.size() ; ++j)
    {
        for(int i = 0; i < v[j].length(); i++)
        {
            if(achk[v[j][i]-'A']==0)
            {
                achk[v[j][i]-'A'] = 1;
                s.push_back(v[j][i]-'A');
            }  
        }
    }   

    for (int i = 0; i < s.size(); ++i)
    {
        arr[s[i]] = 9;
        chk[i] = 1;
        per(8,1);
        chk[i] = 0;
        arr[s[i]] = 0;
    }

    cout<<answer<<"\n";
    return 0;
}