#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll get_sum(ll l, ll r) {
    if (r < l) return 0; // safe guard
    return 1LL * (l + r) * (r - l + 1) / 2;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        ll n, k;
        cin >> n >> k;

        ll L = k;
        ll R = k + n - 1;

        ll l = L, r = R;

        // binary search to balance partition
        while (l < r) {
            ll mid = l + (r - l) / 2;

            if (get_sum(L, mid) < get_sum(mid + 1, R))
                l = mid + 1;
            else
                r = mid;
        }

        ll ans1 = abs(get_sum(L, l) - get_sum(l + 1, R));
        ll ans2 = abs(get_sum(L, l - 1) - get_sum(l, R));

        cout << min(ans1, ans2) << "\n";
    }

    return 0;
}
