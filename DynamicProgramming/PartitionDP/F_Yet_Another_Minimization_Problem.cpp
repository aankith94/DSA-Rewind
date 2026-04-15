#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_cost(const vector<int>& a, int L, int R) {
    vector<int> freq(a.size() + 1, 0);   // safe size
    ll cost = 0;
    for(int i = L; i <= R; i++) {
        int val = a[i];
        cost += freq[val];      // yehi cnt*(cnt-1)/2 build kar raha hai
        freq[val]++;
    }
    return cost;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 4e18));  // bada number (long long)

    dp[0][0] = 0;

    // Base case: 1 part
    for(int i = 1; i <= n; i++) {
        dp[i][1] = get_cost(a, 0, i-1);
    }

    // Main filling
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= min(k, i); j++) {
            dp[i][j] = 4e18;                     // har baar reset karo
            for(int p = j-1; p < i; p++) {       // important: p < i
                ll c = get_cost(a, p, i-1);      // ← yahan galti thi (i-1)
                if(dp[p][j-1] < 4e18) {  // for safety chek
                    dp[i][j] = min(dp[i][j], dp[p][j-1] + c);
                }
            }
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}