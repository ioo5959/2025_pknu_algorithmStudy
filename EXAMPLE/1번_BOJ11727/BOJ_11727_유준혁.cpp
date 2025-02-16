#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'003

int n;
int arr[SIZE];

int main() {
    fastio;
    cin >> n;
    arr[1] = 1;
    arr[2] = 3;
    for (int i = 3; i <= 1000; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10'007;
    }
    cout << arr[n];
    return 0;
}
