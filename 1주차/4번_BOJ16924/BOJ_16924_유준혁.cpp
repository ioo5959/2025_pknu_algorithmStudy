#include <iostream>
#include <vector>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX 103

int n, m, k, x, y, s;
int arr[MAX][MAX];
char grid[MAX][MAX];
char temp[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pair<pair<int, int>, int>> cross;

//십자가 찾기

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp[i][j] = grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '*') {
                int size = 0;
                while (true) {
                    bool canCross = true;
                    for (int dir = 0; dir < 4; dir++) {
                        int ni = i + dx[dir] * (size + 1);
                        int nj = j + dy[dir] * (size + 1);
                        if (ni < 1 || ni > n || nj < 1 || nj > m || grid[ni][nj] != '*') {
                            canCross = false;
                            break;
                        }
                    }
                    if (canCross)
                        size++;
                    else
                        break;
                }
                if (size > 0) {
                    cross.push_back({ {i, j}, size });
                    temp[i][j] = '.';
                    for (int k = 1; k <= size; k++) {
                        temp[i - k][j] = '.';
                        temp[i + k][j] = '.';
                        temp[i][j - k] = '.';
                        temp[i][j + k] = '.';
                    }
                }
            }
        }
    }
    bool val = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (temp[i][j] == '*') {
                val = false;
                break;
            }
        }
        if (!val) break;
    }
    if (!val)
        cout << -1 << "\n";
    else {
        cout << cross.size() << "\n";
        for (auto c : cross) {
            cout << c.first.first << " " << c.first.second << " " << c.second << "\n";
        }
    }

    return 0;
}