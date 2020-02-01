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
    int sz = arr[a][b];
    cout<<sz<<" asaf\n";
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
    for (int i = 0; i < w; ++i)
    {
        int j = 0;
        int flag = 0;
        while(j<h)
        {
            if(arr[j][i]==0&&flag==1)
            {
                while(arr[j][i]==0&&j<h)
                {
                    j++;
                }
                int k = j-1;
                while(v.size()>0)
                {
                    int tmp = v[v.size()-1];
                    arr[k][i] = tmp;
                    k--;
                    v.pop_back();
                }
            }
            else if(arr[j][i]!=0)
            {
                v.push_back(arr[j][i]);
                flag = 1;
                j++;
            }
            else
            {
                j++;
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
        int k = 0;
        while(k<h)
        {
            if(arr[k][j]!=0)
            {
                punch(k,j);
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
            k++;
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