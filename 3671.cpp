#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1000001];
int chk[1000001];
int cidx[8];
string str;
int n;
int answer;
int solve(int num, int cnt)
{
    //cout<<num<<"\n"
    if(cnt==str.length()) return 0;
    int mul = 10;
    for (int i = 1; i < cnt; ++i)
    {
        mul = mul * 10;
    }
    for (int i = 0; i < str.length(); ++i)
    {
        if(cidx[i]==0)
        {
            int temp = str[i]-'0';
            cout<<arr[mul*temp+num]<<" "<<str[i]<<" "<<cnt<<"\n";
            if(arr[mul*temp+num]==0&&chk[mul*temp+num]==0)
            {

                answer++;
                chk[mul*temp+num] = 1;
            }
            cidx[i] = 0;
            solve(mul*temp+num,cnt+1);
            cidx[i] = 1;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    for(int i = 2; i < 1000001; i++)
    {
        if(arr[i]!=0) continue;
        for (int j = 2; j < 1000001; ++j)
        {
            if(i*j>1000000) break;
            if(arr[i*j]==0) arr[i*j] = 1;
        }
    }
    arr[1] = 1;
    arr[0] = 1;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < str.length(); ++j)
        {
            if(chk[str[j]-'0']==0&&arr[str[j]-'0']==0)
            {
                cout<<str[j]-'0'<<"\n";
                answer++;
                chk[str[j]-'0'] = 1;
            }
            cidx[j] = 0;
            cout<<str[j]-'0'<<"\n";
            solve(str[j]-'0',1);
            cidx[j] = 1;
        }
        cout<<answer<<"\n";
        answer = 0;
    }
    return 0;
}