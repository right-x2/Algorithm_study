#include <stdio.h>

using namespace std;
int arr[1001];


int main(int argc, char** argv)
{
    //ios::sync_with_stdio(false); 
    //cin.tie(NULL); 
    //cout.tie(NULL);
    
    int n;
    int cnt = 0;
    int a = 0;
    int b = 0;
    int mid = 0;
    int sum = 0;
    double ans = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&a);
        for (int j = 0; j < a; ++j)
        {
            scanf("%d",&b);
            arr[j] = b;
            sum = sum + b;
        }
        mid = sum/a;
        for (int j = 0; j < a; ++j)
        {
            if(arr[j]>mid)cnt++;
            arr[j] = 0;
        }
        ans = (cnt/(double)a)*100;
        printf("%.3f%%\n", ans);
        mid = 0;
        cnt = 0;
        sum = 0;
    }
    return 0;
}  