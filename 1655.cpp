#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> temp;
int n;
priority_queue<int,vector<int>,less<int> >low;
priority_queue<int,vector<int>,greater<int> >high;
int mid;
int lcnt;
int hcnt;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>num;
        if(i==1) mid = num;
        else if(i%2==0)
        {
            if(num>mid) 
            {
                high.push(num);
            }
            else
            {
                low.push(num);
                high.push(mid);
                mid = low.top();
                low.pop();
            }
        }
        else
        {
            if(num>mid) 
            {
                high.push(num);
                low.push(mid);
                mid = high.top();
                high.pop();

            }
            else
            {
                low.push(num);
            }
        }
        cout<<mid<<"\n";
    }
    return 0;
}  