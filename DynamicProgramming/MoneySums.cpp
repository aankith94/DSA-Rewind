#include<bits/stdc++.h>
using namespace std;


set<int> st;

void moneySum(int i, int sum, vector<int>& coins, vector<vector<int>>& visited) {
    // we have to find the distinct money sum possible
    // we have 2 choices either include in sum or not
    if(i == coins.size()) {
        if(sum != 0) st.insert(sum);
        return;
    }

    if(visited[i][sum]) return;

    visited[i][sum] = 1;

    // not include
    moneySum(i+1, sum, coins, visited);
    // include
    moneySum(i+1, sum + coins[i], coins, visited);
}


int main() {
    int n;
    cin>>n;  // number of coins
   

    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    int totalSum = accumulate(coins.begin(), coins.end(), 0);
    vector<vector<int>> vis(n + 1, vector<int>(totalSum + 1, 0));

    moneySum(0, 0, coins, vis);

    cout << st.size() << "\n";
    for (int x : st) cout << x << " ";
    cout << "\n";

}