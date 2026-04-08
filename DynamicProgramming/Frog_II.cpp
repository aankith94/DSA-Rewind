#include<bits/stdc++.h>
using namespace std;

int minPossibleCost(int n, int k, vector<int>& heights) {
    // dp[i]  = min possible cost to reach at height i
    // Here froh jump from i to i+1, i+2, i+3, i+4,......up to i+k
    vector<int> t(n+1, 1e9);
    t[0] = 0;
    t[1] = abs(heights[1] - heights[0]);

    for(int i=2;i<n;i++) {
        for(int j=1;j<=k;j++) {
            // to avoid runt ime error and segmentation erroe cjek first
            if(i-j >= 0) {
                int temp = t[i-j] + abs(heights[i] - heights[i-j]);
                t[i] = min(temp, t[i]);
            } 
        }
    }

    return t[n-1];
}

int main() {
    int n, k;
    cin>>n >> k;

    vector<int> heights(n);

    for(int i=0;i<n;i++) {
        cin>>heights[i];
    }

    cout<<minPossibleCost(n, k ,heights);

    return 0;
}