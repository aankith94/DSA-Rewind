#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int a = h, b = l;
        if (a > b) swap(a, b);

        int c1 = 0, c2 = 0;
        for (int x : arr) {
            if (x <= a) c1++;
            if (x <= b) c2++;
        }

        cout << min(c1, c2 / 2) << '\n';

    }

    return 0;
}
