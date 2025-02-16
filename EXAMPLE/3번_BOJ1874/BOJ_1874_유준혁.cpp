#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103

stack<int> stk;
int n, k, cnt = 1;
vector<char> c;
bool chk = 1;

int main() {
    fastio;
    cin >> n;
    while (n--) {
        cin >> k;
        while (cnt <= k) {
            stk.push(cnt);
            cnt++;
            c.push_back('+');
        }
        if (stk.top() == k) {
            stk.pop();
            c.push_back('-');
        }
        else {
            chk = 0;
            break;
        }
    }
    if (chk) {
        for (auto cha : c) {
            cout << cha << "\n";
        }
    }
    else
        cout << "NO" << "\n";
    return 0;
}
