#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> s;
int n,m;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
        cin>>a>>b;
        v.push_back(a);
        s.push_back(b);
    }
    sort(v.begin(),v.end());
    sort(s.begin(),s.end());

    if(s[0]*6<=v[0]) cout<<s[0]*n<<"\n";
    else if(n<6) cout<<min(v[0],s[0]*n)<<"\n";
    else cout<<min(((n/6)+1)*v[0],(n/6)*v[0]+(n%6)*s[0])<<"\n";
    return 0;
}  