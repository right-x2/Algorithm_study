#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n,k;
int arr[1001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int cnt = 0;
    cin>>n>>k;
    int idx = 1;
    int flag = 0;
    while(true)
    {
        idx++;
        if(arr[idx]==0)
        {
            arr[idx] = 1;
            cnt++;
            if(cnt==k)
            {
                cout<<idx<<"\n";
                break;
            }
            int tmp = idx;
            for (int i = 2; i < n; ++i)
            {
                if(idx*i>n) break;
                tmp = idx * i;
                if(arr[tmp]==0) 
                {
                    arr[tmp] = 1;
                    cnt++;
                }
                if(cnt==k)
                {
                    flag = 1;
                    cout<<tmp<<"\n";
                    break;
                }
            }
        }
        if(flag==1) break;
    }
    return 0;
}