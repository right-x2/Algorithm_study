#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;
string arr[20001];
bool compare( string a , string b){
	if (a.length() == b.length()){

		return a < b;
	}
	else{
		return a.length() < b.length();
	}
} 


int main(){
	int number;
	cin >> number;
	for (int i = 0; i < number; ++i)
	{
		cin >> arr[i];
	}
	sort( arr , arr+number , compare);
	for (int i = 0; i < number; ++i)
	{	
		if (i==0){
			cout << arr[0] <<'\n';
		}
		else{
			if ( arr[i] != arr[i-1] ){
				cout << arr[i] <<'\n';
			}
		}
	}

}