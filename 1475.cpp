#include <iostream>

using namespace std;
int arr[10];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    int mx = 0;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
    	if(str[i]=='6'||str[i]=='9')
    	{
    		if(arr[6]<=arr[9]) arr[6]++;
    		else arr[9]++;
    	} 
    	else arr[str[i]-'0']++;
    }
    for (int i = 0; i <= 9; ++i)
    {
    	if(arr[i]>mx) mx = arr[i];
    }
    cout<<mx<<"\n";
    return 0;
}  