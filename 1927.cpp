#include <iostream>
#include <queue>
using namespace std;


priority_queue<int,vector<int>,greater<int> > pq;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        if(num==0) 
        {
            if(!pq.empty())
            {
                int tp = pq.top();
                pq.pop();
                cout<<tp<<"\n";
            }
            else cout<<0<<"\n";
        }
        else pq.push(num);
    }
    return 0;
}  