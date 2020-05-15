#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[21];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    string str;
    cin>>n;
    for (int i = 0; i <= n; ++i)
    {
        getline(cin,str);
        string tmp = str;
        if(tmp.substr(0,2)=="ad")
        {
            string ans = str.substr(4,2);
            if(ans.length()==1) arr[ans[0]-'0'] = 1;
            else arr[(ans[0]-'0')*10+(ans[1]-'0')] = 1;
        }
        else if(tmp.substr(0,2)=="al")
        {
            for (int i = 1; i <=20 ; ++i)
            {
                arr[i] = 1;
            }
        }
        else if(tmp[0]=='r')
        {
            string ans = str.substr(7,2);
            if(ans.length()==1) arr[ans[0]-'0'] = 0;
            else arr[(ans[0]-'0')*10+(ans[1]-'0')] = 0;           
        }
        else if(tmp[0]=='c')
        {
            string ans = str.substr(6,2);
            if(ans.length()==1) 
            {
                cout<<arr[ans[0]-'0']<<"\n";
            }
            else cout<<arr[(ans[0]-'0')*10+(ans[1]-'0')]<<"\n";           
        }
        else if(tmp[0]=='t')
        {
            string ans = str.substr(7,2);
            if(ans.length()==1) 
            {
                if(arr[ans[0]-'0']==0) arr[ans[0]-'0'] = 1;
                else arr[ans[0]-'0'] = 0;
            }
            else 
            {
                if(arr[(ans[0]-'0')*10+(ans[1]-'0')]==0) arr[(ans[0]-'0')*10+(ans[1]-'0')] = 1;
                else arr[(ans[0]-'0')*10+(ans[1]-'0')] = 0;
            }
        }
        else if(tmp[0]=='e')
        {
            for (int i = 1; i <=20 ; ++i)
            {
                arr[i] = 0;
            }           
        }
    }
}  