#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int arr[5][9];
int tmp[5][9];
int n;

void run(int idx,int way)
{
    if(way==1)
    {
        int num = arr[idx][8];
        for (int i = 1; i <=8; ++i)
        {

            int tmp = num;
            num = arr[idx][i];
            arr[idx][i] = tmp;
        }
    }
    else
    {
        int num = arr[idx][1];
        for (int i = 8; i >=1; --i)
        {
            int tmp = num;
            num = arr[idx][i];
            arr[idx][i] = tmp;
        }
    }
}

int bfs(int idx,int k,int way)
{
    if(idx==0||idx==5) return 0;
    if(k==0)
    {
        if(tmp[idx+1][7]!=tmp[idx][3])
        {
            if(way==1) 
            {
               run(idx,-1);
               bfs(idx-1,k,-1); 
            }
            else 
            {
              run(idx,1);
              bfs(idx-1,k,1);   
            }
        }
    }
    else
    {
        if(tmp[idx-1][3]!=tmp[idx][7])
        {
            if(way==1) 
            {
               run(idx,-1);
               bfs(idx+1,k,-1); 
            }
            else 
            {
              run(idx,1);
              bfs(idx+1,k,1);   
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
    string str;
    int idx;
    int way;
    for (int i = 1; i <= 4; ++i)
    {
        cin>>str;
        for (int j = 1; j <= 8; ++j)
        {
            arr[i][j] = str[j-1]-'0';
            tmp[i][j] = arr[i][j];
        }
    }
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>idx>>way;
        if(idx>1&&idx<4)
        {
            run(idx,way);
            bfs(idx+1,1,way);
            bfs(idx-1,0,way);
        }
        else if(idx<4)
        {
            run(idx,way);
            bfs(idx+1,1,way);
        }
        else if(idx>1)
        {
            run(idx,way);
            bfs(idx-1,0,way);
        }
        for (int i = 1; i <= 4; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                tmp[i][j] = arr[i][j];
            }
        }
    }
    int ans = 0;
    if(arr[1][1]==1) ans = ans + 1;
    if(arr[2][1]==1) ans = ans + 2;
    if(arr[3][1]==1) ans = ans + 4;
    if(arr[4][1]==1) ans = ans + 8;

    cout<<ans<<"\n";
    return 0;
}