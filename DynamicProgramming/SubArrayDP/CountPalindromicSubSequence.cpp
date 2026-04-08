#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main() {
    string s;
    cin>>s;

    int n = s.size();
    // we have to count the no of palindromic subsequence
    // 1 len
    for(int i=0;i<n;i++) {
        dp[i][i] = 1;
    } 

    // 2 len
    for(int i=0;i<n-1;i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 3; // 2 solo + 1 full
        } else {
            dp[i][i+1] = 2;
        }
    }

    // len >= 3
    for(int len=3;len<=n;len++) {
        for(int i=0;i<n-len+1;i++) {
            int j = len + i -1;

            if(s[i] == s[j]) {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
            } else {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        // if input is 1-based
        // l--; r--;

        cout << dp[l][r] << "\n";
    }
}