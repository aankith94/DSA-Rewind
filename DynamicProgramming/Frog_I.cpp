#include<bits/stdc++.h>
using namespace std;

int minPossibleCost(int n, vector<int>& heights) {
    // dp[i]  = min possible cost to reach at height i
    vector<int> t(n+1, 0);
    t[0] = 0;
    t[1] = abs(heights[1] - heights[0]);

    for(int i=2;i<=n;i++) {
        t[i] = min(
            t[i-1] + abs(heights[i] - heights[i-1]),
            t[i-2] + abs(heights[i] - heights[i-2])
        );
    }

    return t[n-1];
}

int main() {
    int n;
    cin>>n;

    vector<int> heights(n);

    for(int i=0;i<n;i++) {
        cin>>heights[i];
    }

    cout<<minPossibleCost(n, heights);

    return 0;
}