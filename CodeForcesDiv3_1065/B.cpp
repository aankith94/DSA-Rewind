#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long a1 = a[0];
        long long an = a[n - 1];

        // Step 1 — Fix a1 and an to minimize |an - a1|
        if (a1 == -1 && an == -1) {
            // choose lexicographically smallest (0,0)
            a1 = 0;
            an = 0;
        }
        else if (a1 == -1) {
            // choose a1 = an to minimize difference
            a1 = an;
        }
        else if (an == -1) {
            // choose an = a1
            an = a1;
        }

        // Minimum possible value
        cout << llabs(an - a1) << "\n";

        // Step 2 — Construct final array
        a[0] = a1;
        a[n - 1] = an;

        // Fill all internal -1 with 0 for lexicographically smallest array
        for (int i = 1; i < n - 1; i++) {
            if (a[i] == -1) a[i] = 0;
        }

        // Output the final array
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
