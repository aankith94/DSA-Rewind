#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;

        // Only impossible case when x = 1 and k = 1
        if (x == 1 && k == 1) {
            cout << "NO\n";
            continue;
        }

        // If x != 1 -> we can freely use 1
        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) cout << 1 << " ";
            cout << "\n";
            continue;
        }

        // Now x == 1
        // Allowed numbers = 2..k

        if (k == 2) {
            // Only number allowed is 2
            if (n % 2 == 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                cout << n/2 << "\n";
                for (int i = 0; i < n/2; i++) cout << 2 << " ";
                cout << "\n";
            }
        } else {
            // k >= 3 -> we can use {2, 3}
            cout << "YES\n";
            if (n % 2 == 0) {
                cout << n/2 << "\n";
                for (int i = 0; i < n/2; i++) cout << 2 << " ";
                cout << "\n";
            } else {
                cout << n/2 << "\n";
                cout << 3 << " ";
                for (int i = 0; i < (n/2) - 1; i++) cout << 2 << " ";
                cout << "\n";
            }
        }
    }
}
