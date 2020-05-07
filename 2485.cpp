#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int n;
    vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int gap = v[v.size()-1];
    for (int i = 0; i < v.size()-1; ++i)
    {
        if(v[i+1]-v[i]<gap) gap = v[i+1]-v[i];
    }
    for (int i = gap; i > 0; --i)
    {
        int s = v[0];
        int e = v[v.size()-1];
        int idx = 1;
        int cnt = 0;
        int flag = 0;
        while(s<e)
        {
            if(i+s>v[idx]) 
            {
                flag = 1;
                break;
            }
            else if(i+s==v[idx])
            {
                s = v[idx];
                idx++;
            }
            else
            {
                s = s + i;
                cnt++;
            }
        }
        if(flag==0)
        {
            cout<<cnt<<"\n";
            break;
        }
    }
    return 0;
}  