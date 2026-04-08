#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

bool chek(ld mid, ld c) {
    return mid * mid + sqrt(mid) >= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ld c;
    cin >> c;

    ld low = 0.0;
    ld high = max(c, (ld)1.0);

    while(high - low > 1e-6) {
        ld mid = low + (high - low) / 2;

        if(chek(mid, c)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(6) << high << '\n';
    return 0;
}
