#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

vector<int> tmp;
int arr[1001];
int n;
int mx = 0;
void dp()
{
    vector<int> s;
    s.push_back(tmp[tmp.size()-1]);
    arr[tmp.size()-1] = 1;
    for (int i = n-2; i >= 0; --i)
    {
        if(s[s.size()-1]<tmp[i]) s.push_back(tmp[i]);
        else
        {
            for (int j = s.size()-1; j >= -1; --j)
            {

                if(j==-1)
                {
                   s[0] = tmp[i];
                   break; 
                }
                else if(s[j]<tmp[i])
                {
                    s[j+1] = tmp[i]; 
                    break;
                }
            }
        }
        arr[i] = s.size();
    }
}

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
        tmp.push_back(num);
    }
    dp();
    v.push_back(tmp[0]);
    for (int i = 1; i < tmp.size(); ++i)
    {
        if(v[v.size()-1]<tmp[i]) v.push_back(tmp[i]);
        else if(v[v.size()-1]>tmp[i])
        {

            if(mx<v.size()+arr[i-1]-1)mx = v.size()+arr[i-1]-1;
            for(int j = v.size()-1; j >=-1; j--)
            {
                if(j==-1)
                {
                    v[0] = tmp[i];
                    break;
                }
                else if(v[j]<tmp[i])
                {
                    v[j+1] = tmp[i];
                    break;
                }
            }
        }
    }
    if(v.size()>mx) mx = v.size();
    cout<<mx<<"\n";
    return 0;
}