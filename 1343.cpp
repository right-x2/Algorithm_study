#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int flag = 0;
    string str;
    int cnt = 0;
    cin>>str;
    
    for (int i = 0; i < str.length(); ++i)
    {
        if(flag==1&&str[i]!='X'){
            v.push_back(cnt);
            flag = 0;
            cnt = 0;
        }else if(flag==0&&str[i]!='.'){
            cnt = 1;
            flag = 1;
        }else if(flag==1&&str[i]!='.'){
            cnt++;
        }
    }
    if(cnt!=0) v.push_back(cnt);
    int idx = 0;
    int afalg = 0;
    string ans = "";

    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]!='.'){
            if(v[idx]%2!=0){
                cout<<-1<<"\n";
                afalg = 1;
                break;
            }else if(v[idx]%4==0){
                for (int j = 0; j < v[idx]; ++j){
                    ans = ans + 'A';
                }
                i = i + v[idx]-1;
                idx++;
            }else if(v[idx]%4==2){
                for (int j = 0; j < v[idx]-2; ++j){
                    ans = ans + 'A';
                }
                ans = ans + "BB";
                i = i + v[idx]-1;
                idx++;
            }else if(v[idx]%2==0){
                for (int j = 0; j < v[idx]-2; ++j){
                    ans = ans + 'B';
                }
                i = i + v[idx]-1;  
                idx++;             
            }
        }
        else{
            ans = ans + '.';
        }
    }
    if(afalg==0){
        cout<<ans<<"\n";
    }
    

    return 0;
}  