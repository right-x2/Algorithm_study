#include <iostream>
#include <stack>

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
            if(arr[i][j]!=0) cnt++;
        }
    }
    if(cnt<mn) 
    {
        mn = cnt;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n"<<"";
        }
        cout<<"\n"<<"";
    }
    return 0;
}

int punch(int a,int b)
{
    stack <pair<int,int> > stk;
    stk.push(make_pair(a,b));
    while(!stk.empty())
    {
        int i = stk.top().first;
        int j = stk.top().second;
        stk.pop();
        int cnt = arr[i][j];
        arr[i][j] = 0;
        for (int k = 1; k < cnt; ++k)
        {
            if(i-k>=0)
            {
                if(arr[i-k][j]!=0)
                {
                    stk.push(make_pair(i-k,j));
                }
            }
            if(i+k<h)
            {
                if(arr[i+k][k]!=0)
                {
                    stk.push(make_pair(i+k,j));
                }
            }
            if(j-k>=0)
            {
                if(arr[i][j-k]!=0)
                {
                    stk.push(make_pair(i,j-k));
                }
            }
            if(j+k<w)
            {
                if(arr[i][j+k]!=0)
                {
                    stk.push(make_pair(i,j+k));
                }
            }
        }        
    }
    return 0;
}
int tpop()
{
    stack<int> stk;
    for (int i = 0; i < w; ++i)
    {
        int j = 0;
        int flag = 0;
        while(j<h)
        {
            if(arr[j][i]!=0)
            {
                flag = 1;
                stk.push(arr[j][i]);
                j++;
            }
            else if(arr[j][i]==0&&flag==1)
            {
                while(arr[j][i]==0&&j<h) j++;
                while(!stk.empty())
                {
                    j--;
                    int tmp = stk.top();
                    stk.pop();
                    arr[j][i] = tmp;
                }
                while(j>=0)
                {
                    j--;
                    arr[j][i] = 0;
                }
                j = 0;
                flag = 0;     
            }
            else j++;
            
        }
        while(!stk.empty()) stk.pop();
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
                cout<<"daf"<<"fas\n";
                punch(k,j);
                dfs(s+1);
                break;
            }

            k++;
        }
        for (int i = 0; i < h; ++i)
        {
            for (int l = 0; l < w; ++l)
            {
                arr[i][l] = tmp[i][l];
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