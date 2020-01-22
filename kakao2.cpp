#include <string>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

int cal(string str)
{
    int num = 0;
    int ans = 0;
    int cnt = -1;
    vector<int> v;
    if(str.substr(0,2)=="10")
    {
        num = 10;
    }
    else
    {
        num = str[0]-'0';
    }
    for(int i = 1; i < str.length(); i++)
    {
        if(str.substr(i,2)=="10")
        {
            v.push_back(num);
            cnt++;
            num = 10;
            i++;
        }
        else if(str[i]>=48&&str[i]<=57)
        {

            v.push_back(num);
            cnt++;
            num = str[i]-'0';
        }
        else
        {
            if(str[i]=='D'){
                num = pow(num,2);
            }
            else if(str[i]=='T'){

                num = pow(num,3);
                
            }
            else if(str[i]=='*'&&cnt==-1)
            {
                num = num *2;
            }
            else if(str[i]=='*')
            {
                v[cnt] = v[cnt]*2;
                num = num *2;
            }
            else if(str[i]=='#')
            {
                num = num*(-1);
            }
        }

    }
    v.push_back(num);
    for(int i = 0; i < v.size(); i++)
    {
        ans = ans + v[i];
    }
    return ans;
}
int main()
{
    cout<<cal("1D2S#10S")<<"\n";
}