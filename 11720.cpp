#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    int sum = 0;
    string str;
    cin>>n;
    cin>>a;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>str;
        for (int j = 0; j < str.length(); ++j)
        {
            for (int k = 0; k < a; ++k)
            {
                cout<<str[j]<<"";
            }
        }
        cout<<""<<"\n";
    }
    cout<<sum<<"\n";
    return 0;
}  