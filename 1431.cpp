#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> v;
int getsum(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]>='0'&&str[i]<='9') sum = sum + (str[i]-'0');
    }
    return sum;
}
int comp(string a, string b)
{
    if(a.length()>b.length()) return 1;
    else if(a.length()<b.length()) return 0;
    else
    {
        if(getsum(a)>getsum(b)) return 1;
        else if(getsum(a)<getsum(b)) return 0;
        else
        {
            if(a>b) return 1;
            else return 0;
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    string str,tmp;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        v.push_back(str);
    }
    for (int i = 0; i < v.size()-1; ++i)
    {
        for (int j = i+1; j < v.size(); ++j)
        {
            if(comp(v[i],v[j])==1)
            {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<"\n";
    }
}  