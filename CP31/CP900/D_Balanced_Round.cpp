#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        int k;

        cin>>n>>k;

        vector<long long> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        // Implementation
        int counter = 1;
        int longest_ans = 1;

        sort(a.begin(), a.end());

        for(int i=1;i<n;i++) {
            if(abs(a[i] - a[i-1]) <= k) {
                counter++;
            } else {
                counter = 1;
            }

            longest_ans = max(longest_ans, counter);

        }

        cout<<n - longest_ans<<endl;
    }
}