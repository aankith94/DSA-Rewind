#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int CoinPermutations(int n, int sum, vector<int>& coins) {

    vector<int> t(sum+1);
    // here, we have to count the no of permutations not combinations   --   ordered matter karega
    t[0] = 1;
    

    // fill the rest dp
    for(int j=1;j<sum+1;j++) {
        for(int i=1;i<n+1;i++) {
            if(coins[i-1] <= j) {
                t[j] = (t[j] + t[j - coins[i-1]]) % MOD;
            }
        }
    }

    return t[sum];
}

int main() {
    int n, sum;
    cin>>n >> sum;

    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin >> coins[i];
    }

    cout<<CoinPermutations(n, sum, coins);
    return 0;
}