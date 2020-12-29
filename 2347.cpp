#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;
int n;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if (v[0] != 1)

        cout << 1 << "\n";

    else

    {

        int sum = 1; //v[0]


        for (int i = 1; i < n; i++)

        {

                if (v[i] > sum + 1)break;

                sum += v[i];

        }

        cout << sum + 1 << "\n";

    }

    return 0;
}