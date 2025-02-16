#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, k, res, dp[200'200];
queue<int> q;

int main() {
    fastio;
    cin >> n >> k;
    fill(dp, dp + 200'002, 1e9);
    dp[n] = 0;
    q.push(n);
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if (now == k) ++res;
        for (auto nx: {now + -1, now + 1, now * 2}) {
            if (nx < 0 || nx > 100000 || dp[nx] < dp[now] + 1) continue;
            q.push(nx);
            dp[nx] = dp[now] + 1;
        }
    }
    cout << dp[k] <<'\n'<<res;
    return 0;
}
