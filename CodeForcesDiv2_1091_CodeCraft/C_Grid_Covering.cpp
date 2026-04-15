#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if (__gcd(a, n) == 1 && __gcd(b, m) == 1 && __gcd(n, m) <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}