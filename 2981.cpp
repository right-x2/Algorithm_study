#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> box;
int ans;
int n;
int mx;
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

    sort(v.begin(),v.end());
    mx = v[v.size()-1];
    for (int i = mx; i >=1; --i)
    {
        int flag = 0;
        int mod = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            if(j==0) mod = v[j]%i;
            else if(mod!=v[j]%i)
            {
                flag = 1;
                break;
            }
            mod = v[j]%i;
        }
        if(flag==0)
        {
            ans = i;
            break;
        }
        flag = 0;
    }
    int tmp = ans;
    for(int i=2; i<=tmp; i++){

        while(tmp%i ==0){
            box.push_back(i);
            ans/= i;
        }
    }
    box.push_back(tmp);
    sort(box.begin(),box.end());
    for (int i = 0; i < box.size(); ++i)
    {
        if(i==0) 
        {
           cout<<box[i]<<" ";
           tmp = box[i]; 
        }
        else
        {
            if(box[i]!=tmp)
            {
               cout<<box[i]<<" ";
               tmp =  box[i];
            }
        }
    }
    return 0;
}