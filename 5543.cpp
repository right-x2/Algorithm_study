#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
vector<int> s;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    for (int i = 0; i < 3; ++i)
    {
    	cin>>n;
    	v.push_back(n);
    }

    for (int i = 0; i < 2; ++i)
    {
    	cin>>n;
    	s.push_back(n);
    }
    sort(v.begin(), v.end());
    sort(s.begin(), s.end());

    cout<<v[0]+s[0]-50<<"\n";
    return 0;
}  