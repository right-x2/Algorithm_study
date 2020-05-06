#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
int n,m;
int mx = 0;
int check(int k)
{
    string temp = "";
    vector<string> ans;

    for(int i = 0;i < m; i++)
    {

        for(int j = k; j<n; j++)
        {
            temp = temp + v[j][i]; 
        }
        for (int j = 0; j < ans.size(); ++j)
        {
            if(ans[j]==temp) return 0;
        }
        ans.push_back(temp);
        temp = "";
    }
    return 1;
}

int search()
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(check(mid)==1)
        {
            if(mx<mid) mx = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        v.push_back(str);
    }
    search();
    cout<<mx<<"\n";
    return 0;
}  