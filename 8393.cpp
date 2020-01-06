#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,sum = 0;
    cin>>a;
    for (int i = 1; i <= a; ++i)
    {
        sum = sum + i;
    }
    cout<<sum<<"\n";
    return 0;
}  