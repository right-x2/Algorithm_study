#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,num;
    int sum = 0;
    vector<int> va;
    vector<int> vb;

    cin>>a;
    for (int i = 0; i < a; ++i)
    {
    	cin>>num;
    	va.push_back(num);
    }
    for (int i = 0; i < a; ++i)
    {
    	cin>>num;
    	vb.push_back(num);
    }

    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());

    for (int i = 0; i < a; ++i)
    {
    	sum = sum + (va[i]*vb[a-i-1]);
    }
    cout<<sum<<"\n";
    return 0;
}  