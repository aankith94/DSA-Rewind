#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long T;
    cin >> T;

    while(T--) {

        long long n;
        cin >> n;

        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++) {
            cin >> a[i];
        }

        unordered_map<int, int> mpp;
        for(int x : a) mpp[x]++;

        long long oddfre = 0;   // number of values with odd freq
        long long evenfreq = 0; // number of values with even freq

        for(auto &p : mpp) {
            if(p.second % 2 == 1) oddfre++;
            else evenfreq++;
        }

        long long totalDistinct = oddfre + evenfreq;

        // X = how many distinct elements we give odd count in p
        long long X = min(totalDistinct, n);

        // enforce parity condition: X % 2 == n % 2
        if((X % 2) != (n % 2)) X--;

        if(X < 0) X = 0;

        // Among X chosen, only even-frequency elements give benefit +2
        long long takeEven = min(evenfreq, X);

        long long ans = oddfre + 2LL * takeEven;

        cout << ans << "\n";
    }

    return 0;
}
