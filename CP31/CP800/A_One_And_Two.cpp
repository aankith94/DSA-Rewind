#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        int total2 = 0;
        for(int i=0;i<n;i++){ cin>>a[i]; if(a[i]==2) total2++; }
        if(total2 % 2 == 1){
            cout << -1 << '\n';
            continue;
        }
        int need = total2/2;
        if(need == 0){
            cout << 1 << '\n'; // any 1..n-1; smallest is 1
            continue;
        }
        int pref2 = 0;
        int ans = -1;
        for(int i=0;i<n;i++){
            if(a[i]==2) pref2++;
            if(pref2 == need){ ans = i+1; break; } // i is 0-based, k = i+1
        }
        cout << ans << '\n';
    }
    return 0;
}
