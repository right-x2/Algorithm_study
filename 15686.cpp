#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector< pair<int,int> > pv;
vector< pair<int,int> > cpl;
vector< pair<int,int> > pep;
int arr[51][51];
int resum = 1000000;

int com(int s,int n)
{
    int sum = 0;
    int min = 100000;
    if(cpl.size()==n)
    {
        for (int i = 0; i < pep.size(); ++i)
        {
            for (int j = 0; j < cpl.size(); ++j)
            {
                if(abs(pep[i].first-cpl[j].first)+abs(pep[i].second-cpl[j].second)<min)
                {
                    min = abs(pep[i].first-cpl[j].first)+abs(pep[i].second-cpl[j].second);
                }
            }
            sum = sum + min;
            min = 100000;
        }
        if(resum>sum) resum = sum;
        return 0;
    }
    for (int i = s+1; i < pv.size(); ++i)
    {
        cpl.push_back(make_pair(pv[i].first,pv[i].second));
        com(i,n);
        cpl.pop_back();
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j]==2)
            {
                pv.push_back(make_pair(i,j));
                arr[i][j] = 0;
            }
            else if(arr[i][j]==1)
            {
                pep.push_back(make_pair(i,j));
            }
        }
    }
    
    for (int i = 0; i < pv.size(); ++i)
    {
        cpl.push_back(make_pair(pv[i].first,pv[i].second));
        com(i,m);
        cpl.pop_back();
    }
    cout<<resum<<"\n";
    return 0;
}  