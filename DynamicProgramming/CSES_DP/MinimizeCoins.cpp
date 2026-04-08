// #include<bits/stdc++.h>
// using namespace std;
// const int INF = 1e9;

// int minCoins(int n, int x, vector<int>& coins) {
//     // dp[x] = min no of coins to make sum = x
//     vector<int> t(n+1, INF);

//     t[0] = 0;
//     // now fill the rest one
//     for(int i=1;i<=n;i++) {
//         for(auto c : coins) {
//             t[i] = min(t[i], 1 + t[i-c]);
//         }
//     }

//     if(t[n] == INF) return -1;

//     return t[n];
// }

// int main() {
//     int n;
//     int x;
//     cin>>n >> x;

//     vector<int> coins;

//     for(int i=0;i<n;i++) {
//         cin>>coins[i];
//     }

//     cout<<minCoins(n,x, coins);
// }

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;


int minCoins(int n, int sum, vector<int>& coins, vector<vector<int>>& t) {
    // n and sum are changing
    for (int i = 0; i <= n; ++i) t[i][0] = 0;      // zero coins to make sum 0
    for (int j = 1; j <= sum; ++j) t[0][j] = INF;  // impossible with 0 coins

    // fill the rest dp
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(coins[i-1] <= j) {
                t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);   // 1 coins my  be used many times
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return (t[n][sum] >= INF) ? -1 : t[n][sum];
}

int main() {
    int n;
    int sum;
    cin>>n >> sum;
    
    vector<vector<int>> t(n+1, vector<int>(sum+1));

    vector<int> coins(n);

    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    cout<<minCoins(n,sum, coins, t);
}