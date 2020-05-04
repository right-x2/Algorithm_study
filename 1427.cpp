#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    cin>>str;
    for(int i = 0; i < str.length(); i++)
    {
        char min=str[i];
        int idx = i;
        for(int j = i+1; j < str.length(); j++)
        {
            if(min-'0'<str[j]-'0')
            {
                idx = j;
                min = str[j];
            }
        }
        char temp = str[i];
        str[i] = str[idx];
        str[idx] = temp;
    }
    cout<<str<<"\n";
    return 0;
}