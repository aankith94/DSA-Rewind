// Given an array of size “N”; partition it into subarrays where each subarray has size>=2; cost of subarray => {first_element-last_element} --> max Cost/ min cost

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;

    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];

    sort(a.begin()+1, a.end());   // must

    // Implementation --> each subarray has size greater than 2

    vector<ll> dp(n+1, 1e18);

    
    dp[1] = 0;
    

    for(int i=2;i<=n;i++) {
        for(int j=0;j<i;j++) {

            if(i- j >= 2) {
                ll cost = a[j+1] - a[i];
                dp[i] = min(dp[i], dp[j] + cost);
            }
        }
    }

    if(dp[n] == 1e18) cout << -1<<endl;
    else cout << dp[n]<<endl;

}

// Follow UP -> Same as before; but you should strictly divide your array into “k” subarrays;


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> b(n+1);
    for(int i = 1; i <= n; i++) cin >> b[i];

    // if not enough elements
    if(n < 2*k) {
        cout << -1;
        return 0;
    }

    sort(b.begin()+1, b.end());

    // dp[i][p] = max cost using first i elements and p partitions
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, -1e18));

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int p = 1; p <= k; p++) {

            for(int j = i-2; j >= 0; j--) {  // ensure size ≥ 2

                if(dp[j][p-1] == -1e18) continue;

                ll cost = b[j+1] - b[i];

                dp[i][p] = max(dp[i][p], dp[j][p-1] + cost);
            }
        }
    }

    if(dp[n][k] == -1e18) cout << -1;
    else cout << dp[n][k];

    return 0;
}
