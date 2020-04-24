#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int m;
int ans = 0;
int flag = 0;
long long check(int mid){
    long long sum = 0;
    for (int i = v.size()-1; i >=0 ; --i)
    {
        if(v[i]<=mid) return sum;
        sum = sum + v[i]-mid;
    }
    return sum;
}
int search(int low, int high){
    if(high==low) return 0;
    int mid = (high+low)/2;
    long long sum = check(mid);
    if(sum==m){
        ans = mid;
        return 0;
    }else if(sum>m){
        ans = mid;
        search(mid+1,high);
    }else{
        search(low,mid);
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num,n;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());

    search(0,v[v.size()-1]);

    cout<<ans<<"\n";
}  