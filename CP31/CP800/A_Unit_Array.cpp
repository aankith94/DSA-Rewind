#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int k = 0;  // posones
        int l = 0;  // negones

        for(int i=0;i<n;i++) {
            int x;
            cin>>x;

            if(x == -1) l++;
            else {
                k++;
            }
        }

        long long ans = 0;

        while(l > k || l % 2 == 1) {
            l--;
            k++;
            ans++;
        }

        cout<<ans<<endl;
    }

    return 0;
}