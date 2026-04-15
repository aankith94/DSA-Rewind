#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        int q;
        cin>>n>>q;

        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        long long sum = 0;

        for(int i=1;i<=n;i++) {
            sum += a[i];
        }

        vector<long long> prefix(n+1);
        prefix[0] = 0;  // important

        for(int i=1;i<=n;i++) {
            prefix[i] = prefix[i-1] + a[i];
        }

        while(q--) {
            int l;
            int r;
            long long k;

            cin>>l>>r>>k;
        
            // loic = old sum - segment sum + (r-l+1)*k
            // prefix sum techniques -- optimization

            long long segmentSum = prefix[r] - prefix[l-1];
            long long newSum = (r-l+1)*k;
            
            long long ans = sum - segmentSum + newSum;

            if(ans % 2 == 1) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
}