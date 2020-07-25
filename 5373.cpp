#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
char way;
char k;

char arr[6][3][3];


void solve()
{
    if(way=='U')
    {

        int tmp[3][3];
        vector<char> v;
        vector<char> box;
        if(k=='+')
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[j][2-i] = arr[0][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[0][i][j] = tmp[i][j];
                }
            }
            for (int i = 5; i > 1; --i)
            {
                if(i==5)
                {
                   for (int j = 0; j < 3; ++j)
                    {
                        v.push_back(arr[i][0][j]);
                        cout<<arr[i][0][j]<<" ";
                    }                    
                }
                else
                {              
                    for (int j = 0; j < 3; ++j)
                        {
                            box.push_back(arr[i][0][j]);
                            arr[i][0][j] = v[j];
                            cout<<v[j]<<" ";
                        }
                        cout<<"\n"<<"";             

                    for (int j = 0; j < 3; ++j)
                    {
                        v[j] = box[j];
                    }
                    box.clear();
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                arr[5][0][i] = v[i];
            } 
        }
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[2-j][i] = arr[0][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[0][i][j] = tmp[i][j];
                }
            }

            for (int i = 2; i < 6; ++i)
            {
                if(i==2)
                {
                   for (int j = 0; j < 3; ++j)
                    {
                        v.push_back(arr[i][0][j]);
                        cout<<arr[i][0][j]<<" ";
                    }                    
                }
                else
                {              
                    for (int j = 0; j < 3; ++j)
                        {
                            box.push_back(arr[i][0][j]);
                            arr[i][0][j] = v[j];
                            cout<<v[j]<<" ";
                        }
                        cout<<"\n"<<"";             

                    for (int j = 0; j < 3; ++j)
                    {
                        v[j] = box[j];
                    }
                    box.clear();
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                arr[2][0][i] = v[i];
            }             
        }       
    }
    else if(way=='D')
    {

        int tmp[3][3];
        vector<char> v;
        vector<char> box;
        if(k=='+')
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[j][2-i] = arr[1][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[1][i][j] = tmp[i][j];
                }
            }


            for (int i = 2; i < 6; ++i)
            {
                if(i==2)
                {
                   for (int j = 0; j < 3; ++j)
                    {
                        v.push_back(arr[i][2][j]);
                        cout<<arr[i][0][j]<<" ";
                    }                    
                }
                else
                {              
                    for (int j = 0; j < 3; ++j)
                        {
                            box.push_back(arr[i][2][j]);
                            arr[i][2][j] = v[j];
                            cout<<v[j]<<" ";
                        }
                        cout<<"\n"<<"";             

                    for (int j = 0; j < 3; ++j)
                    {
                        v[j] = box[j];
                    }
                    box.clear();
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                arr[2][2][i] = v[i];
            } 
        }
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[2-j][i] = arr[1][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[1][i][j] = tmp[i][j];
                }
            }
            for (int i = 5; i > 1; --i)
            {
                if(i==5)
                {
                   for (int j = 0; j < 3; ++j)
                    {
                        v.push_back(arr[i][2][j]);
                        cout<<arr[i][0][j]<<" ";
                    }                    
                }
                else
                {              
                    for (int j = 0; j < 3; ++j)
                        {
                            box.push_back(arr[i][2][j]);
                            arr[i][2][j] = v[j];
                            cout<<v[j]<<" ";
                        }
                        cout<<"\n"<<"";             

                    for (int j = 0; j < 3; ++j)
                    {
                        v[j] = box[j];
                    }
                    box.clear();
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                arr[5][2][i] = v[i];
            }           
        }       
    }
    else if(way=='F')
    {

        int tmp[3][3];
        if(k=='+')
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[j][2-i] = arr[2][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[2][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[3][0][0];
            int a2 = arr[3][1][0];
            int a3 = arr[3][2][0];

            arr[3][0][0] = arr[0][2][2];
            arr[3][1][0] = arr[0][2][1];
            arr[3][2][0] = arr[0][2][0];

            int b1 = arr[1][0][0];
            int b2 = arr[1][0][1];
            int b3 = arr[1][0][2];

            arr[1][0][0] = a3;
            arr[1][0][1] = a2;
            arr[1][0][2] = a1;

            a1 = arr[5][0][2];
            a2 = arr[5][1][2];
            a3 = arr[5][2][2];

            arr[5][0][2] = b1;
            arr[5][1][2] = b2;
            arr[5][2][2] = b3;

            arr[0][2][2] = a3;
            arr[0][2][1] = a2;
            arr[0][2][0] = a1;
        }
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[2-j][i] = arr[2][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[2][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[5][0][2];
            int a2 = arr[5][1][2];
            int a3 = arr[5][2][2];

            arr[5][0][2] = arr[0][2][2];
            arr[5][1][2] = arr[0][2][1];
            arr[5][2][2] = arr[0][2][0];

            int b1 = arr[1][0][0];
            int b2 = arr[1][0][1];
            int b3 = arr[1][0][2];

            arr[1][0][0] = a1;
            arr[1][0][1] = a2;
            arr[1][0][2] = a3;

            a1 = arr[3][0][0];
            a2 = arr[3][1][0];
            a3 = arr[3][2][0];

            arr[3][0][0] = b3;
            arr[3][1][0] = b2;
            arr[3][2][0] = b1;

            arr[0][2][2] = a3;
            arr[0][2][1] = a2;
            arr[0][2][0] = a1;          
        }       
    }
    else if(way=='R')
    {

        int tmp[3][3];
        if(k=='+')
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[j][2-i] = arr[3][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[3][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[4][0][0];
            int a2 = arr[4][1][0];
            int a3 = arr[4][2][0];

            arr[4][0][0] = arr[0][0][2];
            arr[4][1][0] = arr[0][1][2];
            arr[4][2][0] = arr[0][2][2];

            int b1 = arr[1][0][2];
            int b2 = arr[1][1][2];
            int b3 = arr[1][2][2];

            arr[1][0][2] = a3;
            arr[1][1][2] = a2;
            arr[1][2][2] = a1;

            a1 = arr[2][0][2];
            a2 = arr[2][1][2];
            a3 = arr[2][2][2];

            arr[2][0][2] = b1;
            arr[2][1][2] = b2;
            arr[2][2][2] = b3;

            arr[0][0][2] = a1;
            arr[0][1][2] = a2;
            arr[0][2][2] = a3;
        }
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[2-j][i] = arr[3][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[3][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[2][0][2];
            int a2 = arr[2][1][2];
            int a3 = arr[2][2][2];

            arr[2][0][2] = arr[0][0][2];
            arr[2][1][2] = arr[0][1][2];
            arr[2][2][2] = arr[0][2][2];

            int b1 = arr[1][0][2];
            int b2 = arr[1][1][2];
            int b3 = arr[1][2][2];

            arr[1][0][2] = a1;
            arr[1][1][2] = a2;
            arr[1][2][2] = a3;

            a1 = arr[4][0][0];
            a2 = arr[4][1][0];
            a3 = arr[4][2][0];

            arr[4][0][0] = b1;
            arr[4][1][0] = b2;
            arr[4][2][0] = b3;

            arr[0][0][2] = a1;
            arr[0][1][2] = a2;
            arr[0][2][2] = a3;       
        }       
    }
    else if(way=='L')
    {

        int tmp[3][3];
        if(k=='+')
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[j][2-i] = arr[5][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[5][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[2][0][0];
            int a2 = arr[2][1][0];
            int a3 = arr[2][2][0];

            arr[2][0][0] = arr[0][0][0];
            arr[2][1][0] = arr[0][1][0];
            arr[2][2][0] = arr[0][2][0];

            int b1 = arr[1][0][0];
            int b2 = arr[1][1][0];
            int b3 = arr[1][2][0];

            arr[1][0][0] = a1;
            arr[1][1][0] = a2;
            arr[1][2][0] = a3;

            a1 = arr[4][0][2];
            a2 = arr[4][1][2];
            a3 = arr[4][2][2];

            arr[4][0][2] = b3;
            arr[4][1][2] = b2;
            arr[4][2][2] = b1;

            arr[0][0][0] = a3;
            arr[0][1][0] = a2;
            arr[0][2][0] = a1;
        }
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[2-j][i] = arr[5][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[5][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[4][0][2];
            int a2 = arr[4][1][2];
            int a3 = arr[4][2][2];

            arr[4][0][2] = arr[0][2][0];
            arr[4][1][2] = arr[0][1][0];
            arr[4][2][2] = arr[0][0][0];

            int b1 = arr[1][0][0];
            int b2 = arr[1][1][0];
            int b3 = arr[1][2][0];

            arr[1][0][0] = a1;
            arr[1][1][0] = a2;
            arr[1][2][0] = a3;

            a1 = arr[2][0][0];
            a2 = arr[2][1][0];
            a3 = arr[2][2][0];

            arr[2][0][0] = b3;
            arr[2][1][0] = b2;
            arr[2][2][0] = b1;

            arr[0][0][0] = a1;
            arr[0][1][0] = a2;
            arr[0][2][0] = a3;     
        }       
    }

    else if(way=='B')
    {
        int tmp[3][3];
        if(k=='+')
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[j][2-i] = arr[4][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[4][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[5][0][0];
            int a2 = arr[5][1][0];
            int a3 = arr[5][2][0];

            arr[5][0][0] = arr[0][0][2];
            arr[5][1][0] = arr[0][0][1];
            arr[5][2][0] = arr[0][0][0];

            int b1 = arr[1][2][0];
            int b2 = arr[1][2][1];
            int b3 = arr[1][2][2];

            arr[1][2][0] = a1;
            arr[1][2][1] = a2;
            arr[1][2][2] = a3;

            a1 = arr[3][0][2];
            a2 = arr[3][1][2];
            a3 = arr[3][2][2];

            arr[3][0][2] = b3;
            arr[3][1][2] = b2;
            arr[3][2][2] = b1;

            arr[0][0][0] = a3;
            arr[0][0][1] = a2;
            arr[0][0][2] = a1;
        }
        else
        {
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    tmp[2-j][i] = arr[4][i][j];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    arr[4][i][j] = tmp[i][j];
                }
            }

            int a1 = arr[4][0][2];
            int a2 = arr[4][1][2];
            int a3 = arr[4][2][2];

            arr[4][0][2] = arr[0][2][0];
            arr[4][1][2] = arr[0][1][0];
            arr[4][2][2] = arr[0][0][0];

            int b1 = arr[1][0][0];
            int b2 = arr[1][1][0];
            int b3 = arr[1][2][0];

            arr[1][0][0] = a1;
            arr[1][1][0] = a2;
            arr[1][2][0] = a3;

            a1 = arr[2][0][0];
            a2 = arr[2][1][0];
            a3 = arr[2][2][0];

            arr[2][0][0] = b3;
            arr[2][1][0] = b2;
            arr[2][2][0] = b1;

            arr[0][0][0] = a1;
            arr[0][1][0] = a2;
            arr[0][2][0] = a3;     
        }       
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string a;
    //cin>>n;

    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if(i==0) arr[i][j][k] = 'w';
                else if(i==1) arr[i][j][k] = 'y';
                else if(i==2) arr[i][j][k] = 'r';
                else if(i==3) arr[i][j][k] = 'b';
                else if(i==4) arr[i][j][k] = 'o';
                else if(i==5) arr[i][j][k] = 'g';
            }
        }
    }

    //for (int i = 0; i < n; ++i)
    //{
        //cin>>m;
        //for (int j = 0; i < m; ++j)
        //{
            cin>>a;
        //}
        cout<<a<<"\n";
        way = a[0];
        k = a[1];
        cout<<way<<" "<<k<<"\n";
        solve();
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    cout<<arr[i][j][k]<<" ";
                }
                cout<<"\n"<<"";
            }
            cout<<"\n"<<"";
        }
    //}
    return 0;
}