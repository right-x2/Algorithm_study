#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[8001];
int mx = -4001;
int mn = 4001;
vector<int> v;
vector<int> c;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n,a,sum,cm = 1;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        sum = sum + a;
        if(a>mx) mx = a;
        if(a<mn) mn = a;

        if(a>=0) arr[a] = arr[a] + 1;
        else arr[a+8001];
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    
    for (int i = 0; i < 8001; ++i)
    {
      cout<<arr[i]<<"\n";
      if(arr[i]=cm)
      {
        if(i>4000)
        {
            c.push_back(i-8001);
        }
        else
        {
            c.push_back(i);
        }
      }
      else if(arr[i]>cm)
      {
        if(i>4000)
        {
            c.clear();
            c.push_back(i-8001);
            cm = arr[i];
        }
        else
        {
            c.clear();
            c.push_back(i);
            cm = arr[i];
        }
      }      
    }
    sort(c.begin(),c.end());
    cout<<sum/n<<"\n";
    cout<<v[n/2]<<"\n";
    cout<<c.size()<<"\n";
    /*
    if(c.size()==1)
    {
        cout<<c[0]<<"\n";
    }
    else
    {
        cout<<c[c.size()-2]<<"\n";
    }
    */
    cout<<mx-mn<<"\n";
}  