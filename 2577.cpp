#include <iostream>

using namespace std;

int arr[10];
int main(int argc, char** argv)
{
    //ios::sync_with_stdio(false); 
    //cin.tie(NULL); 
    //cout.tie(NULL);
    int a,b,c,d;
    int sum;
    cin >> a >> b >> c;
    sum = a*b*c;
    while(sum>10)
    {
        d = sum%10;
        sum = sum /10;
        arr[d]++;
    }
    arr[sum]++;
    for (int i = 0; i < 10; ++i)
    {
        cout<<arr[i]<<"\n";
    }
    return 0;
}  