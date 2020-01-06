#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int arr[26] = {-1};
    int n;
    string str;
    cin>>str;
    for (int i = 0; i < 27; ++i)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < str.length(); ++i)
    {
        if(arr[(int)str[i]-97]==-1) arr[(int)str[i]-97] = i;
    }
    for (int i = 0; i < 26; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}  