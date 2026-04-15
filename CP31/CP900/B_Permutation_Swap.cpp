#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> p(n+1);
        for(int i=1;i<=n;i++) cin>>p[i]; 

     // gcd trick
        int k = abs(p[1] -1);
        for(int i=2;i<n;i++) {
            k = __gcd(k, abs(p[i] - i ));
        }

        cout<<k<<endl;

    }
    return 0;
}