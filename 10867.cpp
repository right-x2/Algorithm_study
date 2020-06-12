#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int> > pq;
    int n,num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        pq.push(num);
    }
    num = pq.top();
    cout<<num<<" ";
    pq.pop();
    while(!pq.empty())
    {
        if(pq.top()!=num)
        {
            num = pq.top();
            cout<<num<<" ";
        }
        pq.pop();
    }
    return 0;
}