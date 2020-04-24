#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> s;
int flag = 0;
int ans = 0;
int check(int mx){
    int sum = 0;
    for (int i = 0; i <v.size(); ++i)
    {
        if(mx>v[i]) sum = sum + v[i];
        else{
            sum = sum + mx;
        }
    }
    return sum;
}

int search(int low, int high, int num){
    int mid = (low+high)/2;
    int sum = check(mid);
    if(low==high){
        if(sum<=num) ans = mid;
        return 0;
    }
    if(sum==num){
        ans = mid;
        return 0;
    }
    else if(sum<num){
        ans = mid;
        search(mid+1,high,num);
    }
    else{
        search(low,mid,num);
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>m;
        v.push_back(m);
    }
    cin>>num;

    sort(v.begin(),v.end());
    search(0,v[v.size()-1],num);

    cout<<ans<<"\n";
}  