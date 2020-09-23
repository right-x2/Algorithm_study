#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a = 1,b = 2;

    int n;

    cin>>n;

    

    while(1)
    {
        if(b-a==1&&b*b-a*a>n) break;
        if(b*b-a*a>n) a++;
        else if(b*b-a*a<n)b++;
        else
        {
            v.push_back(b);
            a++;
        }
    }

    if(v.size()==0)cout<<-1<<"\n";
    else
    {
        for (int i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<"\n";
        }
    }
    return 0;
}