#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> ans;
int bound = 0;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,num;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        v.push_back(num);
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if(ans.empty()){
            ans.push_back(v[i]);
            bound = v[i];
        }
        else if(bound>v[i]){
            int idx = ans.size()-1;
            while(idx>=0){
                if(ans[idx]>=v[i]){
                    idx--;
                }
                else break;
            }
            ans[idx+1] = v[i];
            bound = ans[ans.size()-1];
        }
        else if(bound<v[i]){
            ans.push_back(v[i]);
            bound = v[i];
        }
    }
    cout<<ans.size()<<"\n";
    return 0;
}  