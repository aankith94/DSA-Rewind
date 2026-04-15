#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        long long p, q;
        cin >> p >> q;

        if(p == q) {
            cout << -1 << "\n";
            continue;
        }

        if(q != 0) {
            long long old_p = p;

            p = p % q;
            q = q + old_p / 2;
        }

        long long n = p;
        long long m = p + (2 * q) / 4 + 1;

        cout << n << " " << m << "\n";
    }

    return 0;
}