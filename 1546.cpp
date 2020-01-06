#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<double> v;
int arr[10];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    double a,sum = 0;

    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    double mid = v[n-1];
    for (int i = 0; i < n; ++i)
    {
        sum = sum + v[i]/mid*100;
    }
    sum = sum / n;

    cout<<sum<<"\n";

    return 0;
}  