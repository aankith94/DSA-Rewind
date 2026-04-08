#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        int k;
        cin>>n >>k; // k == 1 always


        vector<int> a(n+1);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
        }
        
        int p;
        cin>>p;

        // code
        int x = a[p];  // 0 based indexing
        // ans must be even

        // we have to count the continous blocks in both half -x
        int L = 0;
        int R = 0;
        for(int i=1;i<p;i++) {
            if(a[i] != x && (i == 1 || a[i-1] == x)) {
                L++;
            }
        }

        // Right
        for(int i=p+1;i<=n;i++) {
            if(a[i] != x && (i == p+1 || a[i-1] == x)) {
                R++;
            }
        }

        int ans = 2*(min(L, R) + abs(L - R));  // one to fix it and one to restore p

    

        cout<<ans<<endl;

        
    }
}