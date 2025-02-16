#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 12

int n, m, k;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
string board[S];
map<string, int> mp;

void DFS(int x, int y, int len, string now) {
    if (len >= 6) return;
    mp[now] += 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= n) nx = 0;
        if (ny >= m) ny = 0;
        if (nx < 0) nx = n - 1;
        if (ny < 0) ny = m - 1;
        DFS(nx, ny, len + 1, now + board[nx][ny]);
    }
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    string blank = "";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            DFS(i, j, 1, blank + board[i][j]);
    while (k--) {
        string s;
        cin >> s;
        cout << mp[s] << '\n';
    }
    return 0;
}
