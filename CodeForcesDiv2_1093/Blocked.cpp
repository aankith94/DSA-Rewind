#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        bool ok = true;

        for(int i=1;i<n;i++) {
            if(a[i] == a[i-1]) {
                cout<<-1<<endl;
                ok = false;
                break;
            }
        }

        if(!ok) continue;
        //else
        for(int i=0;i<n;i++) {
            cout<<a[i]<<" ";
        }

        cout<<endl;
    }
    return 0;
}