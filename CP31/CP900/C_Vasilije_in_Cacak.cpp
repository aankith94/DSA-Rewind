#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        ll k;
        ll x;

        cin>>n>>k>>x;

        // Implementation

        // Here TC is less tan O(N)  -- Formula based
        // Logic -> Find the min and max limit of k


        ll min_sum = k*(k+1)/2;
        // max sum = total - sum(n-k)

        ll max_sum =  n*(n+1)/2 - (n-k)*(n-k+1)/2;

        if(x >= min_sum && x <= max_sum) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}