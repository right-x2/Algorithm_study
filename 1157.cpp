#include <iostream>

using namespace std;
int arr[101];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,max = 0,ans = 0,cnt = 0;
    string str;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
        if((int)str[i]>=97) arr[(int)str[i]-32]++;
        else arr[(int)str[i]]++;
    }
    for (int i = 0; i < 101; ++i)
    {
        if(arr[i]>max)
        {
           max = arr[i];
           ans = i; 
        }
    }
    for (int i = 0; i < 101; ++i)
    {
        if(arr[i]==max) cnt++;
    }
    if(cnt>1) cout<<"?"<<"\n";
    else cout<<(char)ans<<"\n";
    
    return 0;
}  