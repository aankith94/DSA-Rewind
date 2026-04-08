// #include<bits/stdc++.h>
// using namespace std;

// int maximumPossibleWeight(int w, vector<long long>& items) {
//     // dp[w][x] = max possible wt of good subset having weight w with the items set up to x
//     int x = 8;

//     vector<vector<int>> t(w+1, vector<int>(x+1));

//     for(int i=0;i<w+1;i++) {
//         for(int j=0;j<x+1;j++) {
//             if(i == 0 || j == 0) {
//                 t[i][j] = 0;
//             }
//         }
//     }

//     // fill the rest dp
//     for(int i=1;i<w+1;i++) {
//         for(int j=1;j<x+1;j++) {
//             if(items[i-1] <= j) {
//                 t[i][j] = max(t[i][j-1], t[i - items[i-1]][j-1]);
//             } else {
//                 t[i][j] = t[i-1][j];
//             }
//         }
//     }

//     return t[w][x];
// }

// int main() {
//     int w;
//     cin>> w;

//     vector<long long> items(8);
//     for(int i=0;i<8;i++) {
//         cin>>items[i];
//     }

//     cout<<maximumPossibleWeight(w, items);

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int maximumPossibleWeight(int w, vector<long long>& items) {
    int n = items.size();

    vector<vector<long long>> t(n + 1, vector<long long>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (items[i - 1] <= j) {
                t[i][j] = max(items[i - 1] + t[i - 1][j - items[i - 1]], t[i - 1][j]);
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][w];
}

int main() {
    int w;
    cin >> w;

    int n;
    cin >> n; // <-- better: read number of items dynamically
    vector<long long> items(n);
    for (int i = 0; i < n; i++) cin >> items[i];

    cout << maximumPossibleWeight(w, items);
    return 0;
}
