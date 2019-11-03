#include <iostream>


using namespace std;

int main()
{
    int n;
    int a;
    int sum = 0;
    cin>>n;
    for (int i = 1; i < 10102; ++i)
    {
        sum = i*i;
        a = n - sum - i;
        if((a*(sum+i)+a) == n)
        {
            cout<<i<<"";
            break;
        }
        a = 0;
        sum = 0;
    }
}