#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[31];
int rchk[31];
int nchk[31];
int root;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int a,b;
    int cnt = 0;

    while(1)
    {
        int zcnt = 0;
        cnt++;
        while(1)
        {
            cin>>a>>b;
            if((a==-1&&b==-1)||(a==0&&b==0)) break;
            v[b].push_back(a);
            rchk[a]=1;
            nchk[b]=1;
        }
        if(a==-1&&b==-1)break;
        int flag = 0;
        for (int i = 0; i <= 30; ++i)
        {
            if(rchk[i]==1&&nchk[i]==0)
            {
                if(root!=0)
                {
                    flag = 1;
                    break;
                }
                else root = i;
            }
        }
        for (int i = 0; i <=30; ++i)
        {
            if(v[i].size()>1)
            {
                flag = 1;
                break;
            }
            else if(v[i].size()==0)zcnt++;
        }
        if(root==0) flag = 1;
        if(zcnt==31) flag = 0;
        if(flag==1) cout<<"Case "<<cnt<<" is not a tree."<<"\n";
        else cout<<"Case "<<cnt<<" is a tree."<<"\n";
        for (int i = 0; i <= 30; ++i)
        {
            rchk[i] = 0;
            nchk[i] = 0;
            v[i].clear();
        }
        root = 0;
    }
    return 0;
}