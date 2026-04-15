#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<ll> pf(n+1, 0), sf(n, 0);

        for(int i = 1; i < n; i++)
            pf[i+1] = pf[i] + abs(a[i]);

        for(int i = n-1; i >= 1; i--)
            sf[i-1] = sf[i] - a[i];

        ll ans = sf[0];

        for(int i = 1; i < n; i++) {
            ans = max(ans, a[0] + pf[i] + sf[i]);
        }

        cout << ans << "\n";
    }
}