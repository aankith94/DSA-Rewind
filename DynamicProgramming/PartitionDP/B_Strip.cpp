#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool chek(int l, ll s, int x, int y, vector<ll>& a) {
    ll mx = LLONG_MIN, mn = LLONG_MAX;

    for(int i = x; i <= y; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    return (y - x + 1 >= l) && (mx - mn <= s);
}

int main() {
    ll n; 
    ll s;
    ll l;
    cin>>n>>s>>l;

    vector<ll> a(n+1);
    for(int i=0;i<n;i++) cin>>a[i];

    // Implementation
    // dp[i] = min no of pieces if arr size is i
    vector<ll> dp(n+1, 1e18);
    dp[0] = 0;

    for(int i=1;i<=n;i++) {
        for(int j=0;j<i;j++) {
            if(chek(l, s, j, i-1, a)) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }

    if(dp[n] >= 1e18) cout<<-1<<endl;
    else {
        cout<<dp[n]<<endl;
    }

    
}