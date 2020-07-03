#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[10000000];
int chk[10000000];
int cidx[8];
string str;
int n;
int answer;

int conv(string temp)
{
    int mul = 1;
    int ans = 0;
    for (int i = temp.length()-1; i >= 0; --i)
    {
        ans = ans + (temp[i]-'0')*mul;
        mul = mul * 10;
    }
    return ans;
}
int solve(string temp, int cnt)
{
    int num = conv(temp);
    //cout<<num<<"\n";
    if(chk[num]==0&&arr[num]==0)
    {
        chk[num] = 1;
        answer++;
    }

    for (int i = 0; i < str.length(); ++i)
    {
        if(cnt<str.length()&&cidx[i]==0)
        {
            cidx[i] = 1;
            solve(temp+str[i],cnt+1);
            cidx[i] = 0;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string temp = "";
    for(int i = 2; i < 10000000; i++)
    {
        if(arr[i]!=0) continue;
        for (int j = 2; j < 10000000; ++j)
        {
            if(i*j>10000000) break;
            if(arr[i*j]==0) arr[i*j] = 1;
        }
    }
    arr[1] = 1;
    arr[0] = 1;
    cin>>n;
    for(int j = 0; j < n; j++)
    {   
        cin>>str;
        for (int i = 0; i < str.length(); ++i)
        {
            cidx[i] = 1;
            temp = str[i];
            solve(temp,1);
            cidx[i] = 0;
        }
        cout<<answer<<"\n";
        for (int i = 0; i < 10000000; ++i)
        {
            chk[i] = 0;
        }
        for (int i = 0; i < 8; ++i)
        {
            cidx[i] = 0;
        }
        answer = 0;
    }
    return 0;
}