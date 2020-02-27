#include <iostream>
#include <stack>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    stack<int> stk;
    int k,num,sum=0;
    cin>>k;
    for (int i = 0; i < k; ++i)
    {
        cin>>num;
        if(num==0)
        {
            stk.pop();
        }
        else
        {
            stk.push(num);
        }
    }
    while(!stk.empty())
    {
        int a = stk.top();
        stk.pop();
        sum = sum + a; 
    }
    cout<<sum<<"\n";
} 