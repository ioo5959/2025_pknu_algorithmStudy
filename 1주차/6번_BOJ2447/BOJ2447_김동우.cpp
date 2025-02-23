#include <iostream>
#include <vector>
using namespace std;

void draw(vector<vector<char>>& grid, int x, int y, int size) {
    if (size == 1) {
        grid[x][y] = '*';
        return;
    }

    int newSize = size / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue; 
            draw(grid, x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N, ' '));

    draw(grid, 0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}