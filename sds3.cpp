#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

string ans = "";
int find(int an[], int max, int len)
{
    if(len<=2) return 0;
    //cout<<count<<"\n";
    vector<int> v;
    int div = (len*len)/4;
    int idx = len/2;
    int min =0;
    int cnt = 0;
    int cnt1 = 0,cnt2 = 0, cnt3 = 0, cnt4 = 0;
    int arr[len][len];
    int arr1[div]={0,};
    int arr2[div]={0,};
    int arr3[div]={0,};
    int arr4[div]={0,};
    int max1=0;
    int max2=0;
    int max3=0;
    int max4=0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            arr[i][j] = an[cnt];
            cnt++;
            cout<<arr[i][j]<<" ";
        }
        cout<<""<<"\n";
    }
    cout<<""<<"\n";
    cnt = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if(i<idx&&j<idx)
            {
                //cout<<arr[i][j]<<" arr\n";
                arr1[cnt1] = arr[i][j];
                if(arr[i][j]>max1) max1 = arr[i][j];
                cnt1++;
            }
            else if(i<idx&&j>=idx)
            {
                //cout<<arr[i][j]<<" 2arr\n";
                arr2[cnt2] = arr[i][j];
                if(arr[i][j]>max2) max2 = arr[i][j];
                cnt2++;
            }
            else if(i>=idx&&j<idx)
            {
                ///cout<<arr[i][j]<<" 3arr\n";
                arr3[cnt3] = arr[i][j];
                if(arr[i][j]>max3) max3 = arr[i][j];
                cnt3++;
            }
            else if(i>=idx&&j>=idx)
            {
                //cout<<arr[i][j]<<" 4arr\n";
                arr4[cnt4] = arr[i][j];
                if(arr[i][j]>max4) max4 = arr[i][j];
                cnt4++;
            }
        }
    }


    cout<<max1<<" max1\n";
    cout<<max2<<" max2\n";
    cout<<max3<<" max3\n";
    cout<<max4<<" max4\n";

    v.push_back(max1);
    v.push_back(max2);
    v.push_back(max3);
    v.push_back(max4);
    sort(v.begin(),v.end());
    min = v[0];
/*
    cout<<min*1.2<<"-------------min";
    cout<<max<<"---------------max\n";*/
    if(min*1.2>=max)
    {
        ans = ans + "1";
        find(arr1,max1,idx);
        find(arr2,max2,idx);
        find(arr3,max3,idx);
        find(arr4,max4,idx);
        
    }
    else{
        ans = ans + "0";
    }
    return 0;

}
int main() {
    int n,num,max = 0;
    int time;
    cin>>time;
    for (int j = 0; j < time; ++j)
    {
        cin>>n;
        vector<int> v;
        int idx = (n*n)/4;
        int div = n/2;
        int arr1[idx]={0,};
        int arr2[idx]={0,};
        int arr3[idx]={0,};
        int arr4[idx]={0,};
        int max1 = 0;
        int max2 = 0;
        int max3 = 0;
        int max4 = 0;
        int idx1 = 0;
        int idx2 = 0;
        int idx3 = 0;
        int idx4 = 0;
        int min = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int k = 0; k <n; ++k)
            {
                cin>>num;
                if (num>max) max = num;


                if(i<div&&k<div)
                {
                    arr1[idx1] = num;
                    if(num>max1) max1 = num;
                    //cout<<arr1[idx1]<<"arr1\n";
                    idx1++;
                }
                else if(i<div&&k>=div)
                {
                    arr2[idx2] = num;
                    if(num>max2) max2 = num;
                    //cout<<arr2[idx2]<<"arr2\n";
                    idx2++;
                }
                else if(i>=div&&k<div)
                {
                    arr3[idx3] = num;
                    if(num>max3) max3 = num;
                    //cout<<arr3[idx3]<<"arr3\n";
                    idx3++;
                }
                else if(i>=div&&k>=div)
                {
                    arr4[idx4] = num;
                    if(num>max4) max4 = num;
                    //cout<<arr4[idx4]<<"arr4\n";
                    idx4++;
                }
                /* code */
            }
        }/*
        cout<<max1<<"\n";
        cout<<max2<<"\n";
        cout<<max3<<"\n";
        cout<<max4<<"\n";*/
        v.push_back(max1);
        v.push_back(max2);
        v.push_back(max3);
        v.push_back(max4);
        sort(v.begin(),v.end());
        min = v[0];
        if(min*1.2>=max)
        {
            ans = ans + "1";
            find(arr1,max1,div);
            find(arr2,max2,div);
            find(arr3,max3,div);
            find(arr4,max4,div);
        }
        else
        {
            ans = ans + "0";
        }
        cout<<""<<"\n";
        cout<<"#"<<"";
        cout<<j+1<<" ";
        cout<<ans<<"\n";
        //cout<<ans.length()<<" le\n";
        ans = "";
    }

    return 0;
}