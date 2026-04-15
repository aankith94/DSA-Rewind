// Given an array of size ‘N’; find the number of ways to partition it such that sum of each part is <=M.

// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long

// ll dp[105];

// int main() {
//     ll n, m;
//     cin >> n >> m;

//     ll a[n+1];
//     for(ll i = 1; i <= n; i++) cin >> a[i];

//     // Implementation
//     dp[0] = 1; //

//     for(int i=1;i<=n;i++) {
//         ll sum = 0;
//         dp[i] = 0;

//         for(int j=i;j>=1;j--) {

//             sum += a[j];
//             if(sum > m) break;

//             dp[i] = dp[i] + dp[j-1];
//         }
//     }

//     cout<<dp[n]<<endl;
// }

// Part 2 - Given an array of size ‘N’; find the number of ways to partition it such that the sum of each part is <=M ; but you should only make k partitions!

// here we define dp[i][k] = number of ways to do partitions till index “i” but the numbers of partitions are exactly k

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[105][105];

int main() {
    ll n, m;
    cin >> n >> m;
    ll k ; 
    cin>>k;

    ll a[n+1];
    for(ll i = 1; i <= n; i++) cin >> a[i];

    // Implementation
    for(ll i=0;i<=100;i++) {
        for(ll j=0;j<=100;j++) {
            dp[i][j] = 0;  // fill initially
        }
    }

    // fill rest dp
    dp[0][0] = 1;  // base case

    for(int i=1;i<=n;i++) {
        for(int p=1;p<=k;p++) {
            ll sum = 0;

            for(ll j=i;j>=1;j--) {
                sum += a[j];

                if(sum > m) break;

                dp[i][p] = dp[i][p] + dp[j-1][p-1]; // transition dp
            }
        }
    }
    cout<<dp[n][k]<<endl;
}

