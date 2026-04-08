#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// coin I - is the no of combination
// coin II - is the no of permutations

int noOfWays(int n, int sum, vector<int>& coins, vector<vector<int>>& t) {
    // we have to count ways
    for(int i=0;i<n+1;i++) t[i][0] = 1;
    for(int j=1;j<sum+1;j++) t[0][j] = 0;

    // fill the rest dp
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(coins[i-1] <= j) {
                t[i][j] = (t[i][j-coins[i-1]] + t[i-1][j]) % MOD;
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int main() {
    // we have to count the distinct no of ways to get desired sum
    int n, sum;
    cin>>n >> sum;

    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }


    vector<vector<int>> t(n+1, vector<int>(sum+1));

    cout<<noOfWays(n, sum, coins, t);


}


