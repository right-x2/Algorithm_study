#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int arr[26];
int chk[26];
int cnt;
vector<string> v;
vector<int> box;
int n,k;
int ans = 0;


int solve(int idx,int cnt)
{
    if(cnt>k) return 0;
    int alcnt = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int flag = 0;
        for (int j = 4; j < v[i].length()-4; ++j)
        {
            if(arr[v[i][j]-'a']==0)
            {
                flag = 1;
                break;
            }
        }
        if(flag==0) alcnt++;
    }
    if(alcnt>ans) ans = alcnt;

    for (int i = idx+1; i < box.size(); ++i)
    {
        arr[box[i]] = 1;
        solve(i,cnt+1);
        arr[box[i]] = 0;
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    cin>>n>>k;
    k = k - 5;
    if(k<0) cout<<0<<"\n";
    else
    {
        for (int i = 0; i < n; ++i)
        {
            cin>>str;
            v.push_back(str);
        }
        string anta = "antic";
        for (int i = 0; i < anta.length(); ++i)
        {
            box.push_back(anta[i]-'a');
            arr[anta[i]-'a'] = 1;
            chk[anta[i]-'a'] = 1;
        }
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 4; j < v[i].length()-4; ++j)
            {
                if(chk[v[i][j]-'a']==0)
                {
                    box.push_back(v[i][j]-'a');
                    chk[v[i][j]-'a'] = 1;
                }
            }
        }
        solve(4,0);
        cout<<ans<<"\n";
    }
    return 0;
}