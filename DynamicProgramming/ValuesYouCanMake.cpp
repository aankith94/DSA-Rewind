#include<bits/stdc++.h>
using namespace std;

// int valuesYouCanMake(int n, int k, vector<int>& coins) {
//     // we have to print the no of suitable x and its values in ascending order

//     // here dp[i][j][x]
//     // i  - no of coins 
//     // j  - having subset sum k
//     // x  - sum of subset from pari's subset having sum as x

//     vector<vector<vector<bool>>> t(n+1, vector<vector<bool>>(k, vector<bool>(k, false)));

//     t[0][0][0] = true;

//     // fill the rest dp
//     for(int i=1;i<n+1;i++) {
//         int c = coins[i-1];  // 0-based indexing
//         for(int j=0;j<k+1;j++) {
//             for(int x=0;x<k+1;x++) {
//                 // exclude
//                 if(t[i-1][j][x]) {
//                     t[i][j][x] = true;
//                 }
//                 // include but subset sum not equal to x
//                 if((j-c) >= 0 && t[i-1][j-c][x]) {
//                     t[i][j][x] = true;
//                 }
//                 if((j-c >= 0) && (x-c >= 0) && t[i-1][j-c][x-c]) {
//                     t[i][j][x] = true;
//                 }
//             }
//         }
//     }

//     // store the result  -- collect al x
//     vector<int> ans;
//     for(int x=0;x<k+1;x++) {
//         if(t[n][k][x]) {
//             ans.push_back(x);
//         }
//     }

//     cout<<ans.size()<<endl;
//     // print all x 
//     for(auto p : ans) {
//         cout<<p<<" ";
//     }

// }

int main() {
    int n, k;
    cin>>n >> k;

    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin>> coins[i];
    }

    // we have to print the no of suitable x and its values in ascending order

    // here dp[i][j][x]
    // i  - no of coins 
    // j  - having subset sum k
    // x  - sum of subset from pari's subset having sum as x

    vector<vector<vector<bool>>> t(n+1, vector<vector<bool>>(k+1, vector<bool>(k+1, false)));

    t[0][0][0] = true;

    // fill the rest dp
    for(int i=1;i<n+1;i++) {
        int c = coins[i-1];  // 0-based indexing
        for(int j=0;j<k+1;j++) {
            for(int x=0;x<k+1;x++) {
                // exclude
                if(t[i-1][j][x]) {
                    t[i][j][x] = true;
                }
                // include but subset sum not equal to x
                if((j-c) >= 0 && t[i-1][j-c][x]) {
                    t[i][j][x] = true;
                }
                if((j-c) >= 0 && (x-c) >= 0 && t[i-1][j-c][x-c]) {
                    t[i][j][x] = true;
                }
            }
        }
    }

    // store the result  -- collect al x
    vector<int> ans;
    for(int x=0;x<k+1;x++) {
        if(t[n][k][x]) {
            ans.push_back(x);
        }
    }

    cout<<ans.size()<<endl;
    // print all x 
    for(auto p : ans) {
        cout<<p<<" ";
    }
}


