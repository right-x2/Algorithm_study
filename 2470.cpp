#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> v;
int a1,a2;
int cur;
int ans;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int flag = 0;
    int n;
    int a;
    int s,e;

    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    s = 0;
    e = n-1;

    ans = v[0] + v[n-1];
    if(ans<0) ans = -ans;
    a1 = v[0];
    a2 = v[n-1];
    while(s<e)
    {
        int box = v[s]+v[e];
        
        if(box<0) 
        {
            flag = 1;
            box = -box;  
        }
        else flag = 0;


        if(box<ans) 
        {
            ans = box;
            a1 = v[s];
            a2 = v[e]; 
        }

        if(flag==0) e--;
        else s++;
    }

    cout<<a1<<" "<<a2<<"\n";
    return 0;
}