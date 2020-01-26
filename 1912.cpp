#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>


using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,sum = 0;
    int max = -1001;
    int box = 0;
    cin>>a;
    for (int i = 0; i <a ; ++i)
    {
        cin>>n;
        if(n>0)
        {

            if(box<0) 
            {
                if(-box<=n) sum = sum + box + n;
                else sum = 0;
                box = 0;
            }
            else
            {
                sum = sum + n;
            }
            if (sum>max)
            {
                max = sum;
            }
        }
        else
        {
            box = box + n;
            if(n>max) max = n;
        }
        cout<<sum<<"\n";
    }
    cout<<max<<"\n";
}  