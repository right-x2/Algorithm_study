#include <iostream>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin>>n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n*2-1; ++j)
        {
            if(i<=j&&j<n*2-i-1)cout<<'*'<<"";
            else if(i>j)cout<<" "<<"";
        }
        cout<<""<<"\n";
    }
    return 0;
}  