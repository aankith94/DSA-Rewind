#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> copy_a = a;
        sort(copy_a.begin(), copy_a.end());

        if(copy_a == a || k > 1) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }    
    return 0;
}
