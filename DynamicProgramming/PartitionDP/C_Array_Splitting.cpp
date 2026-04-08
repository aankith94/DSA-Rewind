// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     // This is the classic Partition Dp Problem
//     int n;
//     int k;
//     cin>>n >>k;
    
//     vector<int> a(n+1);
//     for(int i=1;i<=n;i++) cin>>a[i];

//     // one thing is arr is sorted h
//     vector<vector<long long>> dp(n+1, vector<long long>(k+1, 1e18));

//     // base case
//     for(int i=1;i<=n;i++) {
//         dp[i][1] = a[i] - a[1];  // min shhould be a[1] 
//     }

//     // filling Dp
//     for(int i=1;i<=n;i++) {

//         for(int j=2;j<=k;j++) {
//             if(i < j) continue;  // invalid

//             for(int p=i-1;p>=1;p--) {
//                 long long cost = a[i] - a[p+1];

//                 dp[i][j] = min(dp[i][j],
//                                dp[p][j-1] + cost);
//             }
//         }
//     }

//     cout<<dp[n][k]<<endl;

// }

// Partion dp works but gives tle for large constraints  --> we think o greedy

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // find diff
    vector<long long> diff;
    for(int i=1;i<n;i++) {
        diff.push_back(a[i] - a[i-1]);
    }

    sort(diff.rbegin(), diff.rend());

    // we have to remove the max diff to min cost
    long long ans = a[n-1] - a[0];
    for(int i=0;i<k-1;i++) {
        ans -= diff[i];
    }

    cout<<ans<<endl;
}
