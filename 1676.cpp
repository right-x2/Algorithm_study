#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int cnt = 0;
    cin>>num;
    int temp = 1;
    int k = 1;
    for (int i = 2; i <=num; ++i)
    {
        if(i==10) k = 2;
        if(i>=100) k = 3;
        int mod = 10;
        for (int j = 0; j < k; ++j)
        {
            mod = mod * 10;
        }
        if((temp*i)%10==0)
        {
            temp = temp * i;
            for (int j = 0; j < k; ++j)
            {
                if(temp%10==0)
                {
                    cnt++;
                    temp = temp/10;
                }
                else break;
            }
        }
        else
        {
            temp = (temp*i)%mod;
        }
    }
    cout<<cnt<<"\n";
}   