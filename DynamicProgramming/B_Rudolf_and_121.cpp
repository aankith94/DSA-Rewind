#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<ll>a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        // we ave 3 operations to et arr 0
        for(int i=1;i<n-1;i++) {
            ll x = a[i-1];

            if(x > 0) {
                a[i-1] -= x;
                a[i] -= 2*x;
                a[i+1] -= x;
            }
        }
        // chek
        bool ans = true;
        for(int i=0;i<n;i++) {
            if(a[i] != 0) {
                ans = false;
                break;
            }
        }

        cout<<(ans ? "YES" : "NO")<<endl;

    }
}