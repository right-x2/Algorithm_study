#include <iostream>
#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector< pair<int,string> > dir;
vector<int> solution(string msg) {
    string a;
    vector<int> answer;
    for(int i = 'A'; i <= 'Z' ; i++){
        a = i;
        dir.push_back(make_pair(i-64,a));
    }
    int flag = 0;
    int cnt = 1;
    int s = 0;
    int ch;
    while(true){
        if(s+cnt>msg.length()) break;
        flag = 0;
        string temp;
        temp = msg.substr(s,cnt);
       // cout<<temp<<"\n";
        for(int i = 0; i <=dir.size(); i++ ){
            if(temp==dir[i].second){
                ch = dir[i].first;
                cnt++;
                flag = 1;
                break;
            }
        }
        if(flag==0){
            s = cnt + s-1;
            cnt = 1;
            answer.push_back(ch);
            dir.push_back(make_pair(dir.size()+1,temp));
        } 
    }
    answer.push_back(ch);
    return answer;
}