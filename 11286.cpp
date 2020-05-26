#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    int num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(num==0)
        {
            if(pq.empty()) cout<<0<<"\n";
            else
            {
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }
        else if(num<0)
        {
            pq.push(make_pair(num*-1,num));
        }
        else
        {
            pq.push(make_pair(num,num));
        }
    }
}   