#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> a(n+1);

        a[1] = 2;

        for(int i = 2; i < n; i++) {
            a[i] = 1LL * i * (i + 1);
        }

        a[n] = n;

        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}