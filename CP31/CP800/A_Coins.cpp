#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k % 2 == 1) {     // k is odd
            cout << "YES\n";
        } else {              // k is even
            if (n % 2 == 0)   // n must be even
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
