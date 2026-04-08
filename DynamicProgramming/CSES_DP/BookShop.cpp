#include<bits/stdc++.h>
using namespace std;

int maximumPages(int n, int sum, vector<int>& prices, vector<int>& pages) {
    // it is same as knapsack
    vector<vector<int>> t(n+1, vector<int>(sum+1));

    for(int i=0;i<n+1;i++) {
        for(int j=0;j<sum+1;j++) {
            if(i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    // fill the rest dp
    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {
            if(prices[i-1] <= j) {
                t[i][j] = max(pages[i-1] + t[i-1][j - prices[i-1]], t[i-1][j]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int main() {
    int n, sum;
    cin>> n>> sum;

    vector<int> prices(n);
    vector<int> pages(n);

    for(int i=0;i<n;i++) {
        cin>>prices[i];
    }

    for(int i=0;i<n;i++) {
        cin>>pages[i];
    }

    cout<<maximumPages(n, sum, prices, pages);

    return 0;
}