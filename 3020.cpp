#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;

vector<int> v;
vector<int> s;
int mn = 0;
int alcnt = 1;

int search(int idx)
{
    int low = 0;
    int high = m/2-1;
    int vsum = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]>=idx)
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
            vsum = mid;
        }
    }


    low = 0;
    high = m/2-1;
    int ssum = -1;

    while(low<=high)
    {
        int mid = (low+high)/2;
        if(s[mid]+idx>n)
        {
            high = mid -1;
        }
        else
        {
            low = mid + 1;
            ssum = mid;
        }
    }
    vsum++;
    ssum++;
    return m-ssum-vsum;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>m>>n;
    int num;
    int sum = 0;
    mn = m;
    for (int i = 0; i < m; ++i)
    {
        cin>>num;
        if(i%2==0) v.push_back(num);
        else s.push_back(num);
    }
    sort(v.begin(),v.end());
    sort(s.begin(),s.end());
    for (int i = 1; i <=n; ++i)
    {
        sum = search(i);
        if(sum==mn)alcnt++;
        else if(sum<mn)
        {
            alcnt = 1;
            mn = sum;
        }
    }
    cout<<mn<<" "<<alcnt<<"\n";
}  