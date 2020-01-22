#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr1[3][3];
int arr2[3][3];
int arr3[3][3];
int arr4[3][3];
int arr5[3][3];
int arr6[3][3];
int arr7[3][3];
int arr8[3][3];
int arr9[3][3];
int ans[9][9];
int check[10];
int rc[10];
vector<pair<int,int> > p;

vector<pair<int,int> > real;

vector<int> odd;

int main() {
    int num;
    int time;
    int dot;
    cin>>time;
    for(int n = 0; n < time; n++)
    {
        p.clear();
        real.clear();
        odd.clear();
        cin>>dot;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cin>>num;
                if(i<3&&j<3) arr1[i][j] = num;
                else if(i<3&&j<6) arr2[i][j-3] = num;
                else if(i<3) arr3[i][j-6] = num;
                else if(i<6&&j<3) arr4[i-3][j] = num;
                else if(i<6&&j<6) arr5[i-3][j-3] = num;
                else if(i<6) arr6[i-3][j-6] = num;
                else if(j<3) arr7[i-6][j] = num;
                else if(j<6) arr8[i-6][j-3] = num;
                else arr9[i-6][j-6] = num;
            
                ans[i][j] = num;
            }
        }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(check[ans[i][j]]==0)check[ans[i][j]]=1;
                else
                {
                    p.push_back(make_pair(i,j));
                    for (int k = 0; k < j; ++k)
                    {
                        if(ans[i][j]==ans[i][k]) p.push_back(make_pair(i,k));
                    }
                }
            }
            for (int j = 0; j < 10; ++j)
            { 
                check[j] = 0;
            }
        }
        //sort(p.begin(),p.end());
        if(dot==1)
        {
            for (int i = 0; i < p.size(); ++i)
            {
                int spot = 0;
                int cnt = 0;
                int y = p[i].first;
                int x = p[i].second;
                for (int j = 0; j < 9; ++j)
                {
                    check[ans[j][x]]++;
                }
                for (int j = 1; j < 10; ++j)
                {
                    if(check[j]==0){
                        rc[j]++;
                    }
                }
                for (int j = 0; j < 10; ++j)
                {
                    check[j] = 0;
                }
                for (int j = 0; j < 9; ++j)
                {
                    check[ans[y][j]]++;
                }
                for (int j = 1; j < 10; ++j)
                {
                    if(check[j]==0){
                        rc[j]++;
                    }
                }
                for (int j = 1; j <10 ; ++j)
                {
                    if(rc[j]==2)
                    {
                        odd.push_back(j);
                        real.push_back(make_pair(y+1,x+1));
                        ans[y][x] = j;
                        break;
                    }
                }
                for (int j = 0; j < 10; ++j)
                {
                    check[j] = 0;
                }
                for (int i = 0; i < 10; ++i)
                {
                    rc[i] = 0;
                }
            }
        }
        else
        {
            for (int i = 0; i < p.size(); ++i)
            {

                int spot = 0;
                int cnt = 0;
                int y = p[i].first;
                int x = p[i].second;
                /*
                cout<<y<<"y ";
                cout<<x<<"x\n";
                */
                for (int j = 0; j < 9; ++j)
                {
                    check[ans[j][x]]++;
                }
                for (int j = 1; j < 10; ++j)
                {
                    if(check[j]==0){
                        rc[j]++;
                    }
                }
                for (int j = 0; j < 10; ++j)
                {
                    check[j] = 0;
                }
                for (int j = 0; j < 9; ++j)
                {
                    check[ans[y][j]]++;
                }
                for (int j = 1; j < 10; ++j)
                {
                    if(check[j]==0){
                        rc[j]++;
                    }
                }
                for (int j = 0; j < 10; ++j)
                {
                    check[j] = 0;
                }
                if(y<3&&x<3)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr1[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }
                }
                else if(y<3&&x<6)
                {                
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr2[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }

                }
                else if(y<3)
                {                
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr3[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }

                }
                else if(y<6&&x<3)
                {                
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr4[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }
                }
                else if(y<6&&x<6)
                {                
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr5[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }

                }
                else if(y<6)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {

                            check[arr6[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }

                }
                else if(x<3)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr7[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }
                }
                else if(x<6)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr8[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }
                }
                else
                {
                    for(int j = 0; j < 3; j++)
                    {
                        for(int k = 0; k < 3; k++)
                        {
                            check[arr9[j][k]]++;
                        }
                    }
                    for (int j = 1; j < 10; ++j)
                    {
                        if(check[j]==0)
                        {
                            rc[j]++;
                        }
                    }
                }
                for (int j = 1; j < 10; ++j)
                {
                    if(rc[j]>1)
                    {
                        odd.push_back(j);
                        real.push_back(make_pair(y+1,x+1));
                        ans[y][x] = j;
                    }
                }
                for (int j = 0; j < 10; ++j)
                {
                    check[j] = 0;
                }
                for (int i = 1; i < 10; ++i)
                {
                    rc[i]=0;
                }
            }
        }
        cout<<"#"<<"";
        cout<<n+1<<" ";
        for (int i = 0; i < odd.size(); ++i)
        {
            cout<<real[i].first<<" ";
            cout<<real[i].second<<" ";
            cout<<odd[i]<<" ";
        }
        cout<<""<<"\n";
    }
    return 0;
}