#include <iostream>
using namespace std;

int arr[1001][1001];


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    string temp;

    cin>>str;
    cin>>temp;

    for (int i = 1; i <= str.length(); ++i)
    {
        for (int j = 1; j <= temp.length(); ++j)
        {
            if(str[i-1]==temp[j-1])
            {
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    cout<<arr[str.length()][temp.length()]<<"\n";
    return 0;
}