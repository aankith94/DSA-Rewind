#include<bits/stdc++.h>
using namespace std;

#define ll long long

// // Construct a sequence a
//  containing n
//  integers such that gcd(ai,ai+1)
//  †
//  is distinct over all 1≤i≤n−1
// . It is guaranteed that at least one sequence a
//  exists.

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        // First construct the array b --> eiter of primes or odds
        vector<ll> b(n+1);
        for(int i=0;i<=n;i++) {
            b[i] = 2*i + 1;
        }
        // from b get the ans
        
        for(int i=0;i<n;i++) {
            cout<<b[i]*b[i+1]<<endl;
        }

        cout<<endl;

    }
    return 0;
}