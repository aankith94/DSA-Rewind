#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];

        vector<vector<ll>> dp(n+1, vector<ll>(7, INF));

        ll ans = INF;

        // base case
        for(int x=1;x<=6;x++) {
            dp[1][x] = (a[1] != x);  // 1 if diff or 0 if same
        }

        // fill rest dp
        for(int i=2;i<=n;i++) {
            for(int x=1;x<=6;x++) {
                for(int y=1;y<=6;y++) {
                    // y to track prev cost
                    if(x == y || x + y == 7) continue;

                    dp[i][x] = min(dp[i][x], dp[i-1][y] + (a[i] != x));  // curr cost + prev cost
                }
            }
        }

        // ans = min(dp[n][x] - x from 1 to 6)
        for(int x=1;x<=6;x++) {
            ans = min(ans, dp[n][x]);
        }


        cout << ans << "\n";
    }
}