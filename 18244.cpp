#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[101][11][2];
int dp(int idx,int cnt, int way, int len)
{
    int a = 0,b = 0;
    if(len==n) 
    {
        arr[len][idx][way] = 1;
        return arr[len][idx][way];
    }
    if(arr[len][idx][way]!=0) return arr[len][idx][way];
    if(way==1)
    {
        if(cnt<2&&idx<9) a = dp(idx+1,cnt+1,way,len+1);
        if(idx-1>=0) b = dp(idx-1,1,0,len+1);
    }
    else
    {
        if(cnt<2&&idx>0) a = dp(idx-1,cnt+1,way,len+1);
        if(idx+1<=9) b = dp(idx+1,1,1,len+1);
    }
    arr[len][idx][way] = arr[len][idx][way]+ a + b;
    if (idx==0)
    {
        cout<<arr[len][idx][way]<<"\n";
    }
    return arr[len][idx][way];
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < 10; ++i)
    {
        dp(i,1,1,1);
    }
    for (int i = 1; i <=n ; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            cout<<arr[i][j][0]<<" ";
        }
        cout<<"\n"<<"";
    }
    cout<<"\n"<<"";
    return 0;
}