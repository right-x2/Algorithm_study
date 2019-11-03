#include <iostream>
using namespace std;
 
int map[5][5], arr[12];
bool visit[5][5], check[12];
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1, 2, 2, -2, -2, -1, 1, -1, 1 };
const int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1, -1, 1, -1, 1, 2, 2, -2, -2 };
int L;
 
bool dfs(int d, int x, int y, int dir) {
    if (d == L) { return true; }
    if (map[y][x] != arr[d] && !visit[y][x]) { return false; }
    if (map[y][x] != arr[d] && visit[y][x]) {
        x += dx[dir]; y += dy[dir];
        if (x <= 0 || y <= 0 || x > 3 || y > 3) return false;
        return dfs(d, x, y, dir);
    }
    visit[y][x] = true;
    for (int i = 0; i < 16; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > 3 || ny > 3) continue;
        if (dfs(d + 1, nx, ny, i)) return true;
    }
    visit[y][x] = false;
    return false;
}
 
int main(void) {
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            map[i][j] = j + (i - 1) * 3;
 
    cin >> L;
 
    for (int i = 0; i < L; i++) {
        cin >> arr[i];
        if (check[arr[i]]) {
            cout << "NO" << '\n';
            return 0;
        }
        check[arr[i]] = true;
    }
 
    int sx, sy;
    if (arr[0] == 1) { sx = 1; sy = 1; }
    else if (arr[0] == 2) { sx = 2; sy = 1; }
    else if (arr[0] == 3) { sx = 3; sy = 1; }
    else if (arr[0] == 4) { sx = 1; sy = 2; }
    else if (arr[0] == 5) { sx = 2; sy = 2; }
    else if (arr[0] == 6) { sx = 3; sy = 2; }
    else if (arr[0] == 7) { sx = 1; sy = 3; }
    else if (arr[0] == 8) { sx = 2; sy = 3; }
    else { sx = 3; sy = 3; }
    if (dfs(0, sx, sy, -1)) { cout << "YES" << '\n'; }
    else { cout << "NO" << '\n'; }
    return 0;
}