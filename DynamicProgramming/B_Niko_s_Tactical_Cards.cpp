#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        } 

        vector<ll> b(n+1);
        for(int i=1;i<=n;i++) {
            cin>>b[i];
        }

        // implementation
        vector<ll> dp_max(n+1, 0);
        vector<ll> dp_min(n+1, 0);
        

        dp_max[1] = max(-a[1], b[1]);
        dp_min[1] = min(-a[1], b[1]);

        for(int i=2;i<=n;i++) {
            ll x1 = dp_max[i-1] - a[i];
            ll x2 = dp_min[i-1] - a[i];
            ll x3 = b[i] - dp_max[i-1];
            ll x4 = b[i] - dp_min[i-1];

            dp_max[i] = max({x1, x2, x3, x4}); 
            dp_min[i] = min({x1, x2, x3, x4});
        }

        cout<<dp_max[n]<<endl;
    }
}