#include <bits/stdc++.h>
using namespace std;

int dp[5000][5000];   // for palindrome cheking
int dp1[5000][5000];  // for counting

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // length = 1
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        dp1[i][i] = 1;
    }

    // length = 2
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
        }

        dp1[i][i+1] = dp1[i][i] + dp1[i+1][i+1] + dp[i][i+1];  // count - here dp[i][i+1] is because if s[i] == s[j] then 1 else 0
    }

    // length >= 3
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
            }

            dp1[i][j] = dp1[i][j-1] + dp1[i+1][j]
                        - dp1[i+1][j-1] + dp[i][j];  // same here also
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

        cout << dp1[l][r] << "\n";
    }

    return 0;
}