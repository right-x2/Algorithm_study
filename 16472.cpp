#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int arr[27];

vector<int> v;
int ans = 1;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    int len;
    cin>>n;
    cin>>str;
    int cnt = 1;
    int s = 0;
    int e = 0;
    len = str.length();
    arr[str[0]-'a'] = 1;
    while(e<len)
    {
        if(cnt<=n)
        {
            e++;
            if(e==len) break;
            if(arr[str[e]-'a']==0) cnt++;
            if(cnt<=n)
            {
                if(e-s+1>ans) ans = e-s+1;
            }
            arr[str[e]-'a']++;
        }
        else
        {
            arr[str[s]-'a']--;
            if(arr[str[s]-'a']==0) cnt--;
            s++;
        }

    }

    cout<<ans<<"\n";
    return 0;
}