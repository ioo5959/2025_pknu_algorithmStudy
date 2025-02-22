#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	// 도로 길이
	vector<long long> road(N - 1);
	// 주유소의 기름 가격 저장함
	vector<long long> price(N);

	for (int i = 0; i < N - 1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	long long totalCost = 0;
	long long minPrice = price[0];

	// 모든 도로 순회
	for (int i = 0; i < N - 1; i++) {
		if (price[i] < minPrice) {
			// 최소 기름
			minPrice = price[i];
		}
		totalCost += minPrice * road[i];
	}

	cout << totalCost << endl;

	return 0;
}