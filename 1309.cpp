#include <iostream>
#include <vector>
using namespace std;

int arr[100001][3];
int solve(int a,int b){
    if(a==0){
        arr[a][b] = 1;
        return arr[a][b];
    }
    if(a<0) return 0;
    if(arr[a][b]!=0) return arr[a][b];
    if(b==1){
        arr[a][b] = (solve(a-1,2)%9901)+(solve(a-1,0)%9901);
    }else if(b==2){
        arr[a][b] = (solve(a-1,1)%9901)+(solve(a-1,0)%9901);
    }
    else{
        arr[a][b] = (solve(a-1,0)%9901) + (solve(a-1,1)%9901) +(solve(a-1,2)%9901);
    }
    return arr[a][b];
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,m,num;
    cin>>n;

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;

    for (int i = 1; i <n ; ++i)
    {
        arr[i][1] = (arr[i-1][2]+arr[i-1][0])%9901;
        arr[i][2] = (arr[i-1][1]+arr[i-1][0])%9901;
        arr[i][0] = (arr[i-1][1]+arr[i-1][0]+arr[i-1][2])%9901;
    }

    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        sum = (sum + arr[n-1][i])%9901;
    }
    cout<<sum<<"\n";
    return 0;
}  