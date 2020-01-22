#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

long long n,k,mx = -1;

vector< pair<int, int> > v;
vector< pair<int, int> > tmp;

int bfs(int start, int cnt)
{
    if(cnt==n-2-k)
    {
        long long sum = 0;
        tmp.push_back(make_pair(v[n-1].first,v[n-1].second));
        //cout<<" "<<"\n";
        for (int i = 0; i < tmp.size()-1; ++i)
        {
            //cout<<tmp[i].first<<" "<<tmp[i].second<<"\n";
            sum = sum + abs(tmp[i].first-tmp[i+1].first) + abs(tmp[i].second-tmp[i+1].second);
        }
        tmp.pop_back();
        if(mx == -1) mx = sum;
        else if(sum<mx) mx = sum;
        return 0;
    }
    for (int i = start; i < n-1; ++i)
    {
        tmp.push_back(make_pair(v[i].first,v[i].second));
        bfs(i+1,cnt+1);
        tmp.pop_back();
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int test_case = 1; test_case <= T; ++test_case)
    {
        int a,b;
        cin>>n>>k;
        for (int i = 0; i < n; ++i)
        {
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        tmp.push_back(make_pair(v[0].first,v[0].second));
        bfs(1,0);
        cout<<"#"<<test_case<<" "<<mx<<"\n";
        tmp.clear();
        v.clear();
        mx = -1;
    }
}  