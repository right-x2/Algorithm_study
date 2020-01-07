#include <iostream>


using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    int cnt = 0;
    cin>>str;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i]=='c')
        {
            if((str[i+1]=='='||str[i+1]=='-')&&i+1<str.length())
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        else if(str[i]=='d')
        {
            if(str[i+1]=='z'&&i+1<str.length())
            {
                if(str[i+2]=='='&&i+2<str.length())
                {
                    cnt++;
                    i = i + 2;
                }
                else
                {
                    cnt = cnt + 2;
                    i = i + 1;
                }
                
            }
            else if(str[i+1]=='-'&&i+1<str.length())
            {
                cnt++;
                i = i + 1;
            }
            else cnt++;
        }
        else if(str[i]=='l')
        {
            if(i+1<str.length()&&str[i+1]=='j')
            {
                i = i + 1;
                cnt++;
            }
            else
            {
                cnt++;
            }
        }
        else if(str[i]=='n')
        {
            if(i+1<str.length()&&str[i+1]=='j')
            {
                i = i + 1;
                cnt++;
            }
            else
            {
                cnt++;
            }
        }
        else if(str[i]=='s')
        {
            if(i+1<str.length()&&str[i+1]=='=')
            {
                i = i + 1;
                cnt++;
            }
            else
            {
                cnt++;
            }
        }
        else if(str[i]=='z')
        {
            if(i+1<str.length()&&str[i+1]=='=')
            {
                i = i + 1;
                cnt++;
            }
            else
            {
                cnt++;
            }
        }
        else cnt++; 

    }
    cout<<cnt<<"\n";
    return 0;
}  