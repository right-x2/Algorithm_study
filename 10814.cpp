#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct P{
    int age;
    string name;

    bool operator <(const P &b) const{
        return this->age < b.age;
    }
};
vector< pair<P,int> >v;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector< pair<int,string> >pv;
    int n,a;
    string b;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        P p;
        p.age = a;
        p.name = b;
        v.push_back(make_pair(p,i));
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i)
    {
        cout<<v[i].first.age<<" "<<v[i].first.name<<"\n";
    }
    return 0;
}  