#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n;
stack<int> st;
vector<char> res;

int main() {
    fastio;
    cin >> n;
    int idx = 1;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        while (idx <= x) {
            res.push_back('+');
            st.push(idx++);
        }
        if (st.top() == x) {
            res.push_back('-');
            st.pop();
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (auto c: res) cout << c << '\n';
    return 0;
}
