#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int suneetWins = 0;

        // All possible orders of playing cards
        vector<pair<int, int>> suneet = {{a1, a2}, {a2, a1}};
        vector<pair<int, int>> slavic = {{b1, b2}, {b2, b1}};

        for (auto s : suneet) {
            for (auto sl : slavic) {
                int sWins = 0, lWins = 0;

                // Round 1
                if (s.first > sl.first) sWins++;
                else if (s.first < sl.first) lWins++;

                // Round 2
                if (s.second > sl.second) sWins++;
                else if (s.second < sl.second) lWins++;

                if (sWins > lWins) suneetWins++;
            }
        }

        cout << suneetWins << "\n";
    }
    return 0;
}
