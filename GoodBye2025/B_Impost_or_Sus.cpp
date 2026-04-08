// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         string s;
//         cin >> s;

//         int n = s.size();
//         int ans = 0;

//         // ensure at least two 's'
//         if (s[0] == 'u') ans++;
//         if (s[n - 1] == 'u') ans++;

//         for(int i=1;i<n-1;i++) {
//             if(s[i] == 'u' && s[i+1] != 's')ans++;
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

void solve() {
    string r;
    cin >> r;
    int n = r.size();

    // Assertion as requested: ensure string only contains 's' or 'u'
    for (char c : r) {
        assert(c == 's' || c == 'u');
    }

    int ans = 0;

   
    if (r[0] == 'u') {
        r[0] = 's';
        ans++;
    }
    if (r[n - 1] == 'u') {
        r[n - 1] = 's';
        ans++;
    }

    
    for (int i = 0; i < n - 1; i++) {
        if (r[i] == 'u' && r[i + 1] == 'u') {
            r[i + 1] = 's';
            ans++;
        }
    }


    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}