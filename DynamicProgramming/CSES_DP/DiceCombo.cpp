#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int diceCombo(int n, vector<int>& t) {
    // we have to fill it
    // we have the fun as ways[i] = ways[i-1] +ways[i-2]+......+ways[i-6]
    t[0] = 1;  // 1 ways for n=0

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=6;j++) {
            if(i-j >= 0) {
                t[i]= (t[i] + t[i-j]) % MOD;
            }
        }
    }
    return t[n];
}

int main() {
    int n;
    cin>>n;


    vector<int> t(n+1, 0);


    cout<<diceCombo(n, t);

    return 0;

}