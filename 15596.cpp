#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];
long long sum(vector<int> v)
{
    long long sm = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        sm = sm + v[i];
    }
    return sm;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    return 0;
}  