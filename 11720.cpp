#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    int sum = 0;
    string str;
    cin>>n;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
        sum = str[i]-'0'+sum;
    }
    cout<<sum<<"\n";
    return 0;
}  