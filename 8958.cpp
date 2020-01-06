#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[81];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,cnt = 0;
    int sum = 0;
    string str;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        for (int j = 0; j < str.length(); ++j)
        {
            if(str[j]=='O')
            {
                cnt++;
                sum = sum + cnt;
            }
            else
            {
                cnt = 0;
            }
        }
        cout<<sum<<"\n";
        sum = 0;
        cnt = 0;
    }
    return 0;
}  