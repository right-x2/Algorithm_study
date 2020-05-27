#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


int arr[1000001];
int chk[11];
int tg;
int flag = 0;
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > >pq;
int bfs(int sum, int mul, int cnt)
{
    if(mul>tg)
    {
        if(chk[1]==0&&mul<=500000&&arr[sum+mul]==0)
        {
            arr[sum+mul] = 1;
            flag = 1;
            pq.push(make_pair(cnt+1,sum+mul));
        }
        if(sum>tg)
        {
            if(arr[sum%10]==0)
            {
                pq.push(make_pair(cnt,sum%10));
                arr[sum%10] = 1; 
            }      
        }
        if(arr[sum]==0)
        {
           pq.push(make_pair(cnt,sum));
           arr[sum] = 1; 
        }
        return 0;
    }
    else if(mul*10>tg)
    {
        if(arr[sum]==0)
        {
           pq.push(make_pair(cnt,sum));
           arr[sum] = 1; 
        }      
    }


    int num = (tg/mul)%10;
    for (int i = 0; i < 10; ++i)
    {
        int a = num - i;
        if(a<0) a = a + 10;
        if(chk[a]==0)
        {
            tt++;
            bfs(sum + a*mul,mul*10,cnt+1);
        }
    }
    tt = 0;
    for (int i = 1; i < 10; ++i)
    {
        int a = num + i;
        if(a>9) a = a - 10;
        if(chk[a]==0)
        {
            tt++;
            bfs(sum+a*mul,mul*10,cnt+1);
        }
    }
    return 0;   
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int f = 0;
    int n,num,k=0;
    cin>>tg;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>num;
        chk[num] = 1;
    }
    int temp = tg;
    while(temp>=10)
    {
        k++;
        temp = temp/10;
    }
    pq.push(make_pair(0,100));
    num = tg%10;
    while(!pq.empty())
    {
        int cnt = pq.top().first;
        int std = pq.top().second;
        pq.pop();
        if(cnt==k&&f==0)
        {
            f = 1;
            num = tg%10;
            for (int i = 0; i < 10; ++i)
            {
                int a = num - i;
                if(a<0) a = a + 10;
                if(chk[a]==0)
                {
                    tt++;
                    bfs(a,10,1);
                }
            }
            for (int i = 1; i < 10; ++i)
            {
                int a = num + i;
                if(a>9) a = a - 10;
                if(chk[a]==0)
                {
                  bfs(a,10,1);
                }
            }         
        }
        if(std==tg)
        {
            cout<<cnt<<"\n";
            break;
        }
        if(std>0&&std>tg&&arr[std-1]==0)
        {
            arr[std-1]=1;
            pq.push(make_pair(cnt+1,std-1));
        }            
        if(std<tg&&arr[std+1]==0)
        {
            arr[std+1]=1;
            pq.push(make_pair(cnt+1,std+1));
        }          
    }
    return 0;
}   