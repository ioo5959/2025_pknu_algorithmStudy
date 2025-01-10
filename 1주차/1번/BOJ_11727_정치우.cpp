#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
int n, dp[1002];

int main() {
    fastio;
    cin >> n;
    dp[1] = 1, dp[2] = 3;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
    cout << dp[n];
    return 0;
}
