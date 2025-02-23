#include <iostream>
#include <vector>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

vector<pair<int, int>> three;
int arr[10][10], temp[10][10];
int n, m, ans = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (temp[nx][ny] == 0) {
            temp[nx][ny] = 2;
            dfs(nx, ny);
        }
    }
}

void threeWall(int cnt, int start) {
    if (cnt == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                temp[i][j] = arr[i][j];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 2)
                    dfs(i, j);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 0)
                    count++;
            }
        }
        ans = max(ans, count);
        return;
    }

    for (int i = start; i < three.size(); i++) {
        int x = three[i].first;
        int y = three[i].second;
        arr[x][y] = 1;
        threeWall(cnt + 1, i + 1);
        arr[x][y] = 0;
    }
}


int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                three.push_back({ i, j });
            }
        }
    }

    threeWall(0, 0);
    cout << ans << "\n";
    return 0;
}