// #include<bits/stdc++.h>
// using namespace std;

// int t[2005][2005];

// int knapsack(int s, int n, vector<int>& V, vector<int>& W, vector<int>& K) {
//     // we have 2 choices
//     // Base case  -- smallest possible input
//     if(n == 0 || s == 0) return 0;

//     if(t[n][s] != -1) return t[n][s];

//     if (W[n - 1] > s) return t[n][s] = knapsack(s, n - 1, V, W, K);

//     int ans = knapsack(s, n-1, V, W, K);

//     for(int i=1;i<=K[n-1];i++) {
//         if(i*W[n-1] <= s) {
//             // we have choices
//             ans = max(i*V[n-1] + knapsack(s-i*W[n-1], n-1, V, W, K), ans);
//         } else break;
//     }
//     return t[n][s] = ans;
// }

// int main() {
//     int S;  // capacity
//     int N;

//     cin>>S >>N;

//     vector<int> V(N);
//     vector<int> W(N);
//     vector<int> K(N);  // it is copies

//     for(int i=0;i<N;i++) {
//         cin>>V[i] >>W[i]>>K[i];

//     }
//     // now , we have to return 
//     cout<< knapsack(S, N, V, W, K) <<endl;
// }



#include <bits/stdc++.h>
using namespace std;

int dp[105][1005]; // memoization table: dp[n][s]

// Recursive bounded knapsack
int knapsack(int s, int n, vector<int>& V, vector<int>& W, vector<int>& K) {
    if (n == 0 || s == 0) return 0;

    if (dp[n][s] != -1) return dp[n][s];

    int ans = knapsack(s, n - 1, V, W, K); // skip current item

    // try taking 1 to K[n-1] copies if possible
    for (int i = 1; i <= K[n - 1]; i++) {
        if (i * W[n - 1] <= s) {
            ans = max(ans, i * V[n - 1] + knapsack(s - i * W[n - 1], n - 1, V, W, K));
        } else break;
    }

    return dp[n][s] = ans;
}

int main() {
    int S, N;
    cin >> S >> N;

    vector<int> V(N), W(N), K(N);
    for (int i = 0; i < N; i++) cin >> V[i] >> W[i] >> K[i];

    memset(dp, -1, sizeof(dp));

    cout << knapsack(S, N, V, W, K) << endl;
    return 0;
}
