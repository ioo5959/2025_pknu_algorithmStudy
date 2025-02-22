#include <iostream>
#include <vector>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX 100'003

int road[MAX], price[MAX];
int n, m, ans = 0;

//int형으로 할 시, sum의 범위가 최대 1,000,000,000,000,000,000 이므로 int형으론 불가. long long 타입 사용해야함
long long solve(int n) {
    long long minPrice = 1e9;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (price[i] < minPrice) minPrice = price[i];
        sum += minPrice * road[i];
    }
    return sum;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> road[i];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << solve(n);

    return 0;
}