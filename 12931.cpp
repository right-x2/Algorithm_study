#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
int n;
int s;
void div()
{
    for(int i = s; i < n ;i++)
    {
        v[i] = v[i]/2;
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int cnt = 0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    while(1)
    {
        int flag = 0;
        for (int i = s; i < n; i++)
        {
            if(v[i]==0)
            {
                s = i;
            }
            else if(v[i]%2==1)
            {
                flag = 1;
                v[i]--;
                cnt++;
            }
        }
        if(s==n-1&&v[s]==0) break;
        if(flag==0)
        {
            cnt++;
            div();
        }
        
        
    }
    cout<<cnt<<"\n";
    return 0;
}