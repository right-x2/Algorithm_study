#include <iostream>
#include <vector>


using namespace std;

int n;
long long int m;
vector<int> box;
int a[6][6];
int b[6][6];


vector<int> mul(vector<int> v, vector<int>s)
{
    vector<int> ans;
    int sum;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = v[cnt];
            b[i][j] = s[cnt];
            cnt++;
        }
    }



    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            sum = 0;

            for (int k = 0; k < n; ++k)
            {

                sum = (sum + (a[i][k] * b[k][j])%1000)%1000;
            }
            ans.push_back(sum);
        }
        
    }

    return ans;
}

vector<int> solve(long long int pow)
{
    vector<int> half;
    if(pow==1) return box;

    
    if(pow%2==1)
    {
        return mul(solve(pow-1),box);
    }

    half = solve(pow/2);
    if(pow%2==0)
    {
        return mul(half,half);
    }
}



int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    int cnt = 0;
    vector<int> answer;
    cin>>n>>m;

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>num;
            box.push_back(num);
        }
    }

    answer = solve(m);

    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<answer[cnt]%1000<<" ";
            cnt++;
        }
        cout<<"\n";
    }
    return 0;
}