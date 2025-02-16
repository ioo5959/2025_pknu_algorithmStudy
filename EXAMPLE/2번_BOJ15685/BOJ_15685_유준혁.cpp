#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103

int n, x, y, d, g, cnt = 0;
int board[SIZE][SIZE];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> dir;

int main() {
    fastio;
    cin >> n;
    while (n--) {
        dir.clear();
        cin >> x >> y >> d >> g;
        board[x][y] = 1;
        x += dx[d];
        y += dy[d];
        board[x][y] = 1;
        dir.push_back(d);
        while (g--) {
            int dir_size = dir.size();
            for (int j = dir_size - 1; j >= 0; j--) {
                int tmp_d = (dir[j] + 1) % 4;
                x += dx[tmp_d];
                y += dy[tmp_d];
                board[x][y] = 1;
                dir.push_back(tmp_d);
            }
        }
        //정사각형 찾기
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1]) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
