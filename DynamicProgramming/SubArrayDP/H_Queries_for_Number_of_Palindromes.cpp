#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001];  // for palindrome chek
int dp1[5001][5001];  // for counting

int main() {
    string s;
    cin>>s;

    int n = s.size();

    // 1 len
    for(int i=0;i<n;i++) {
        dp[i][i] = 1;  // palindrome
        dp1[i][i] = 1;
    }

    // 2 len
    for(int i=0;i<n-1;i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
        }

        dp1[i][i+1] = dp1[i][i] + dp1[i+1][i+1] + dp[i][i+1];
    }

    // len >= 3
    for(int len=3;len<=n;len++) {
        for(int i=0;i<n-len+1;i++) {
            int j=i + len -1;

            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
            }

            dp1[i][j] = dp1[i][j-1] + dp1[i+1][j] - dp1[i+1][j-1] + dp[i][j];
        }
    }


    int q;
    cin>>q;
    
    while(q--) {
        int l;
        int r;
        cin>>l >> r;

        l--;
        r--;  // 1 based

        cout<<dp1[l][r]<<endl;
    }

    return 0;
}