#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

// after swapping both arrays are sorted in ascending

int goodSubsets(int n, vector<int>& a, vector<int>& b) {
    // soln - a simple observation
    int ans = 2;  // 2 to hoga hi

    for(int i=1;i<n;i++) {
        if(min(a[i], b[i]) >= max(a[i-1], b[i-1])) {
            ans *= 2;
            ans %= MOD;
        }
    }

    return ans;
}

int main() {
    int T;
    cin>>T;

    while(T--) {
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        for(int i=0;i<n;i++) {
            cin>>b[i];
        }

        cout<<goodSubsets(n, a, b)<<endl;
    }
}