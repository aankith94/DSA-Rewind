#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll ct, ch, cu;
    if (!(cin >> ct >> ch >> cu)) return;

    // Base Calculation:
    // H always takes 3 rows.
    // U always takes 3 rows.
    // T takes 2 rows.
    ll n = (3 * ch) + (3 * cu) + (2 * ct);

    // Interaction: 
    // Every T-block can "pair" with a U-block to reduce the U-block's 
    // effective footprint from 3 rows to 2.
    ll pairs = min(ct, cu);
    n -= pairs;

    // Boundary Condition:
    // If we ONLY have T-blocks, they follow a 2k + 1 pattern.
    // If any H or U blocks are present, they act as a "flat edge" 
    // that absorbs that extra +1.
    if (ct > 0 && ch == 0 && cu == 0) {
        n += 1;
    }

    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}