#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cf(vector< vector<int> > lock)
{
    for (int i = 1; i <= lock.size(); ++i)
    {
        for (int j = 1; j <= lock.size(); ++j)
        {
            if(lock[i][j]==0)
            {
                return i;
            }
        }
    }
    return 10;
}

vector< vector<int> > turn(vector< vector<int> > key)
{
    return key;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {

    bool answer = true;
    return answer;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

}  