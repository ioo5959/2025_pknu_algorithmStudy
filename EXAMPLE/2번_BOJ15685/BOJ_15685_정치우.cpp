#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 102

int n, x, y, d, g, res;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
vector<int> dir;
bool vis[S][S];

void BFS() {
    int s = dir.size();
    for (int i = s - 1; i >= 0; i--) {
        int newD = (dir[i] + 1) % 4;
        x += dx[newD], y += dy[newD], vis[x][y] = 1;
        dir.push_back(newD);
    }
}

int main() {
    fastio;
    cin >> n;
    while (n--) {
        cin >> y >> x >> d >> g;
        vis[x][y] = 1, x += dx[d], y += dy[d], vis[x][y] = 1;
        dir.push_back(d);
        while (g--) BFS();
        dir.clear();
    }
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            if (vis[i][j] == 1 && vis[i + 1][j] == 1 && vis[i][j + 1] == 1 && vis[i + 1][j + 1])
                ++res;
    cout << res;
    return 0;
}