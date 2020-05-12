#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    long long low = 1;
    long long high = n;
    long long mx = 1;
    long long std = 0;
    while(low<=high)
    {
        long long mid = (low+high)/2;
        if(mid%2==1) std = (mid/2)*(1+mid)+(mid+1)/2;
        else std = (mid/2)*(1+mid);

        if(std>n)
        {
            high = mid -1;
        }
        else
        {
            low = mid +1;
            if(mx<mid) mx = mid;
        }
    }   
    cout<<mx<<"\n";
    return 0;
}  