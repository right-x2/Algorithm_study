#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>


using namespace std;

int arr[16][16];
int n,w,h;
int mn = 256;

int chk()
{
    int cnt = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cout<<arr[i][j]<<" ";
            if(arr[i][j]!=0) cnt++;
        }
        cout<<"\n"<<"";
    }
    cout<<"\n"<<"";
    if(cnt<mn) mn = cnt;
}

int punch(int a,int b)
{
    if(arr[a][b]==1)
    {
        arr[a][b] = 0;
        return 0;
    }
    int sz = arr[a][b];
    arr[a][b] = 0;
    for (int i = 1; i < sz; ++i)
    {
        if(a-i>=0)
        {
            if(arr[a-i][b]!=0)
            {
                punch(a-i,b);
            }
        }
        if(a+i<h)
        {
            if(arr[a+i][b]!=0)
            {
                punch(a+i,b);
            }
        }
        if(b-i>=0)
        {
            if(arr[a][b-i]!=0)
            {
                punch(a,b-i);
            }
        }
        if(b+i<w)
        {
            if(arr[a][b+i]!=0)
            {
                punch(a,b+i);
            }
        }
    }
    return 0;
}
int tpop()
{
    vector<int> v;
    for (int j = 0; j < w; ++j)
    {
        for (int k = 0; k < h; ++k)
        {
            if(arr[k][j]==0&&v.size()!=0)
            {
                int mid = k;
                while(arr[mid][j]==0) mid--;
                mid++;
                int cnt = 0;
                while(!v.empty())
                {
                    int a = v[v.size()-1];
                    v.pop_back();
                    arr[mid+cnt][j] = a;
                    cnt--;
                }
                arr[mid+cnt][j] = 0;
            }
            else if(arr[k][j]!=0)
            {
                v.push_back(arr[k][j]);
            }
        }
        v.clear();
    }
    return 0; 
}
int dfs(int s)
{
    tpop();
    if(s==n)
    {
        chk();
        return 0;
    }
    int tmp[16][16]={0,};
    for (int j = 0; j < h; ++j)
    {
        for (int k = 0; k < w; ++k)
        {
            tmp[j][k] = arr[j][k];
        }
    }

    for (int j = 0; j < w; ++j)
    {
        for (int k = 0; k < h; ++k)
        {
            if(arr[k][j]!=0)
            {
                punch(j,k);
                dfs(s+1);
                for (int i = 0; i < h; ++i)
                {
                    for (int l = 0; l < w; ++l)
                    {
                        arr[i][l] = tmp[i][l];
                    }
                }
                break;
            }
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n>>w>>h;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin>>arr[i][j];
        }
    }
    dfs(0);
    cout<<mn<<"\n";
}  