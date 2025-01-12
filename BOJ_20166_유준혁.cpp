#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103

int n, m, k, cnt, ind;
char board[11][11];
string kval, val;
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };

void dfs(int x, int y, int ind) {
    if (ind == kval.size()) {
        cnt++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = x + dy[i];
        if (nx < 0) nx = n - 1;
        if (nx >= n) nx = 0;
        if (ny < 0) ny = m - 1;
        if (ny >= m) ny = 0;

        if (kval[ind] == board[nx][ny]) {
            dfs(nx, ny, ind + 1);
        }
    }
}


void solved() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (kval[0] == board[i][j]) {
                dfs(i, j, 1);
            }
        }
    }
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    while (k--) {
        cnt = 0;
        cin >> kval;
        solved();
        cout << cnt << "\n";
    }

    return 0;
}
