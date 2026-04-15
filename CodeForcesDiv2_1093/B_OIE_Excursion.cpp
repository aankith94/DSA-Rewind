#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        set<long long> st;

        for(int i = 0; i < n; i++) {
            long long val = (m - (a[i] + i + 1) % m) % m;
            st.insert(val);
        }

        if(st.size() == m) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}