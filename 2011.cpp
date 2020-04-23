#include <iostream>
#include <vector>
using namespace std;

vector<int> v;


int arr[5001][27];
string str;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
        int ten = 0;
        int ten2 = 0;
        int num = 0;
        int nxt = 0;
        int idx = str[i]-'0';
        if(idx==0) continue;
        if(i==0) arr[i][idx] = 1;
        if(i+1<str.length()){
            num = str[i+1]-'0';
            arr[i+1][num] = (arr[i+1][num] + arr[i][idx])%1000000;
            if((idx*10)+num<=26) ten = idx*10 + num;
            if(i==0&&ten!=0) arr[i][ten] = 1;
        }
        if(i+2<str.length()){
            nxt = str[i+2]-'0';
            if(num!=0&&(num*10)+nxt<=26) arr[i+1][(num*10)+nxt] = (arr[i+1][(num*10)+nxt] + arr[i][idx])%1000000;
            if(ten!=0) arr[i+2][nxt] = (arr[i+2][nxt] + arr[i][ten])%1000000;
        }
        if(i+3<str.length()){
            int nxnum = str[i+3]-'0';
            if((nxt*10)+nxnum<=26) ten2 = nxt*10 + nxnum;
            if(nxt!=0&&ten2!=0) arr[i+2][ten2] = (arr[i+2][ten2] + arr[i][ten])%1000000;;
        }
    }
    int sum = 0;
    if(str.length()>1)
    {
        for (int i = 10; i <=26; ++i)
        {
            sum = (sum + arr[str.length()-2][i])%1000000;;
        }
    }

    for(int i = 1; i <= 26; i++)
    {
        sum = (sum + arr[str.length()-1][i])%1000000;;
    }
    cout<<sum<<"\n";
}  