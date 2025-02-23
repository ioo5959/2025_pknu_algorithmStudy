#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// flydongwoo : " 너무 어려워요 ... "

int N, M;
// 연구소 지도
vector<vector<int>> lab;
// 빈공간 위치
vector<pair<int, int>> emptySpace;
// 바이러스 위치
vector<pair<int, int>> virus;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 바이러스 퍼뜨리기
int spread(vector<vector<int>> copied) {
	queue<pair<int, int>> q;

	// 초기 위치를 큐에 삽입함
	for (auto v : virus) {
		q.push(v);
	}

	// 바이러스를 퍼뜨림
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 연구소 범위에서 빈칸이면 바이러스 전파함
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && copied[nx][ny] == 0) {
				copied[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	// 안전한 곳 계산함
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copied[i][j] == 0) {
				safe++;
			}
		}
	}

	return safe;
}

int main() {
	cin >> N >> M;
	lab.resize(N, vector<int>(M));

	// 연구소 상태
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) emptySpace.push_back({ i, j }); 
			if (lab[i][j] == 2) virus.push_back({ i, j });
		}
	}

	int maxSafe = 0;

	// 빈 칸의 개수
	int numEmpty = emptySpace.size();
	vector<int> comb(numEmpty, 0);

	// 벽을 세우는 위치를 결정함
	for (int i = 0; i < 3; i++) {
		comb[i] = 1;
	}
	
	sort(comb.begin(), comb.end());

	// 가능한 벽 세우는 조합을 탐색함
	do {
		vector<vector<int>> copied = lab;

		for (int i = 0; i < numEmpty; i++) {
			if (comb[i] == 1) {
				int x = emptySpace[i].first;
				int y = emptySpace[i].second;
				copied[x][y] = 1;
			}
		}

		int safe = spread(copied);
		maxSafe = max(maxSafe, safe);

	} while (next_permutation(comb.begin(), comb.end()));

	cout << maxSafe << endl;

	return 0;
}