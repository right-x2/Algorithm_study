#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> s;
int n,m,l;
int a,b;
int mx;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int c,d;
    int num;
    int box = 0;
    cin>>n>>m>>l;

    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }

    

    for (int i = 0; i < m; ++i)
    {
        sort(v.begin(),v.end());
        for (int j = 0; j < v.size(); ++j)
        {
            cout<<v[j]<<" ";
        }
        cout<<"\n";
        c = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            d = v[j];
            if(d-c>mx)
            {
                mx = d-c;
                a = c;
                b = d;
            }
            c = d;
        }
        d = l;
        if(d-c>mx)
        {
            mx = d-c;
            a = c;
            b = d;
        }
        if(mx%2==0)
        {
            box = a+mx/2;
        }
        else
        {
            box = a+mx/2+1;
        }
        v.push_back(box);
    }
    cout<<box<<"\n";
    return 0;
}