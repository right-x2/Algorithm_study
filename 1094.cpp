#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    int a = 64;
    int cnt = 1;
    while(a>n)
    {
        a = a/2;
    }
    while(1)
    {
        int sum = 0;
        for (int i = 0; i < v.size(); ++i)
        {
            sum = sum + v[i];
        }
        if(sum+a>n)a = a/2;
        else if(sum+a==n)
        {
            cout<<v.size()+1<<"\n";
            break;
        }
        else
        {
            v.push_back(a);
            a = a / 2;
        }
    }
    return 0;
}