#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

vector<int> v;
vector<int> temp;
int n;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }
    temp.push_back(v[0]);
    for (int i = 1; i < n; ++i)
    {
        int idx = temp.size()-1;
        if(temp[idx]<v[i]) temp.push_back(v[i]);
        else
        {
            while(idx>=0&&temp[idx]>v[i])
            {
                idx--;
            }
            idx++;
            temp[idx] = v[i];
        } 
    }
    cout<<v.size()-temp.size()<<"\n";
}  