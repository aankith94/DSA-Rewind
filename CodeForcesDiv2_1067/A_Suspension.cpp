#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int n;
        cin>>n;

        int y, r;
        cin>>y>>r;  // red and yellow

        // code here!
        int ans = 0;
        if(r > n) {
            ans = r;
        } else {
            // r is less than n
            ans += r;
            int left = n - r;
            int result = y/2;
            if(result < left) {
                ans += result;
            } else {
                ans += left;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}