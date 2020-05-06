#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
queue<long long> q;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long n,m,num,sum = 0;
    long long cnt = 0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(sum+num<m)
        {
            q.push(num);
            sum = sum + num;
        }
        else if (sum+num>m)
        {
            while(!q.empty()&&sum+num>m)
            {
                long long tptp = q.front();
                sum = sum - tptp;
                q.pop();
            }
            if(sum+num==m)cnt++;
            sum = sum + num;
            q.push(num);
        }
        else if(sum+num==m)
        {
            q.push(num);
            sum = sum + num;
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}  