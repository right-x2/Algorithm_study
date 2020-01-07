#include <iostream>

using namespace std;

int arr[123];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    char chr;
    int n,flag=0,cnt = 0;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>str;
        chr = str[0];
        for (int j = 1; j < str.length(); ++j)
        {
            if(chr!=str[j])
            {
                if(arr[(int)chr]==1)
                {
                    flag = 1;
                }
                arr[(int)chr]++;
                chr = str[j];
            }
            
        }
        if(arr[(int)chr]==1) flag = 1;
        for (int j = 0; j < 123; ++j)
        {
            arr[j] = 0;
        }
        if(flag==0) cnt++;
        flag = 0;
    }
    cout<<cnt<<"\n";
    return 0;
}  