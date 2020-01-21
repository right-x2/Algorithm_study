#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> v;
vector<int> tmp;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    tmp.push_back(v[0]);
    for (int i = 1; i < n; ++i)
    {
        a = v[i];
        int tsze = tmp.size()-1;
        if(tmp[tsze]<a) tmp.push_back(a);
        else if(tmp[tsze]>=a)
        {
            if(tsze==0) tmp[0]=a;
            else
            {
                for (int j = tmp.size()-2; j >=0 ; j--)
                {
                    if(a>tmp[j])
                    {
                        tmp[j+1] = a;
                        break;
                    }
                }
                if(a<tmp[0]) tmp[0] = a;
            }
        }
    }
    cout<<tmp.size()<<"\n";
}  