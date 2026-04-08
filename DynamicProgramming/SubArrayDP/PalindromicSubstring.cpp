#include <bits/stdc++.h>
using namespace std;

int dp[5000][5000];

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // length = 1
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // length = 2
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
        }
    }

    // length >= 3
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
            }
        }
    }

    // queries
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        // if input is 1-based
        // l--; r--;

        cout << (dp[l][r] ? "YES" : "NO") << "\n";
    }

    return 0;
}