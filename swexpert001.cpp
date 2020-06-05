#include <vector>
#include<iostream>
using namespace std;
int arr[13][13];
vector< pair<int,int> >v;
int mcnt;
int answer;
int n;

int dfs(int y,int x, int idx,int cnt, int num)
{
    if(mcnt>v.size()-idx+cnt) return 0;

    if(idx==v.size()) 
    {    
        if(mcnt<cnt)
        {
            mcnt = cnt;
            answer = num;
        }
        else if(mcnt==cnt&&answer>num)
        {
            mcnt = cnt;
            answer = num;
        }
        return 0;
    }

    int k = y-1;
    for(int i = y-1; i>=-1; i--)
    {
        if(i==-1) 
        {
            if(idx+1==v.size()) dfs(0,0,idx+1,cnt+1,num+y);
            else dfs(v[idx+1].first,v[idx+1].second,idx+1,cnt+1,num+y);
            break;
        }
        if(arr[i][x]!=0)break;
        else
        {
            k--;
            arr[i][x] = 1;
        }
    }
    for (int i = y-1; i >k; i--)
    {
        arr[i][x] = 0;
    }
    k = y+1;
    for(int i = y+1; i<=n; i++)
    {
        if(i==n) 
        {
            if(idx+1==v.size()) dfs(0,0,idx+1,cnt+1,num+n-y-1);
            else dfs(v[idx+1].first,v[idx+1].second,idx+1,cnt+1,num+n-y-1);
            break;
        }
        if(arr[i][x]!=0)break;
        else
        {
            k++;
            arr[i][x] = 1;
        }
    }
    for (int i = y+1; i <k; ++i)
    {
        arr[i][x] = 0;
    }
    k = x-1;
    for(int i = x-1; i>=-1; i--)
    {
        if(i==-1) 
        {
            if(idx+1==v.size()) dfs(0,0,idx+1,cnt+1,num+x);
            else dfs(v[idx+1].first,v[idx+1].second,idx+1,cnt+1,num+x);
            break;
        }
        if(arr[y][i]!=0)break;
        else
        {
            k--;
            arr[y][i] = 1;
        }
    }
    for (int i = x-1; i >k; --i)
    {
        arr[y][i] = 0;
    }
    k = x+1;
    for(int i = x+1; i<=n; i++)
    {
        if(i==n) 
        {
            if(idx+1==v.size()) dfs(0,0,idx+1,cnt+1,num+n-x-1);
            else dfs(v[idx+1].first,v[idx+1].second,idx+1,cnt+1,num+n-x-1);
            break;
        }
        if(arr[y][i]!=0)break;
        else
        {
            k++;
            arr[y][i] = 1;
        }
    }
    for (int i = x+1; i <k; ++i)
    {
        arr[y][i] = 0;
    }


    if(idx+1==v.size()) dfs(0,0,idx+1,cnt,num);
    else dfs(v[idx+1].first,v[idx+1].second,idx+1,cnt,num);


    return 0;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int test_case;
    int T;

    
    for(int i = 0; i <= 12 ;i++)
    {
        for(int j = 0; j <= 12 ;j++)
        {
            arr[i][j] = 0;
        }
    }
    mcnt = 0;
    answer = 0;
    n = 0;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                cin>>arr[i][j];
                if(i>0&&i<n-1&&j>0&&j<n-1&&arr[i][j]==1) v.push_back(make_pair(i,j));
            }
        }
        for(int i = 0; i < v.size(); i++)
        {
            dfs(v[i].first,v[i].second,i,0,0);
        }
        cout<<"#"<<test_case<<" "<<answer<<"\n";
        v.clear();
        mcnt = 0;
        answer = 0;
        for(int i = 0; i <= 12; i++)
        {
            for(int j = 0; j <= 12 ;j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}