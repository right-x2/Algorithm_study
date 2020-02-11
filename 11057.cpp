#include <iostream>

using namespace std;

int arr[10001][10];
int n;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int sum = 0;
    cin>>n;
    for (int i = 0; i < 10; ++i)
    {
        arr[0][i] = 1;
    }
    sum = 10;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < 10; ++j)
        {
            for (int k = j; k < 10; ++k)
            {
                arr[i][k] = arr[i][k]%10007+arr[i-1][j]%10007;
                sum = sum + arr[i-1][j];
            }
        }
    }
    sum = sum%10007;
    cout<<sum<<"\n";
} 