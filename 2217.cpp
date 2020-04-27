#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int check(int mid)
{
    int flag = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if((double)mid/(v.size()-i)<=(double)v[i])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num, mid,mn;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int low = 1;
    int high = v[v.size()-1]*v.size();
    mn = 0;
    while(low<=high)
    {
        mid = (low+high)/2;
        int std = check(mid);
        if(std==1){
            if(mid>mn) mn = mid;
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    cout<<mn<<"\n";
    return 0;
}