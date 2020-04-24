#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> s;
int flag = 0;

int search(int low, int high, int num){
    int mid = (low+high)/2;
    if(low==high){
        return 0;
    }
    if(v[mid]==num){
        flag=1;
        return 0;
    }
    else if(v[mid]<num){
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
    int num,n,m;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>num;
        s.push_back(num);
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < m; ++i)
    {   flag = 0;
        search(0,v.size(),s[i]);
        cout<<flag<<" ";
    }
}  