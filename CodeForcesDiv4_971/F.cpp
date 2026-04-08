// This is Firefly Queries -- cyclic shift
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        long long n, q;
        cin>> n >> q;   // n is the length of array and q is the number of queries
        vector<long long> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i]; // array
        }
       
        // calculating the sum
        long long sum = 0;
        for(int i=0;i<n;i++) sum += a[i];   // sum of 1 block

        // Build A = a+a instead of a2
        vector<long long> A(2*n);
        for(int i=0;i<n;i++) {
            A[i] = a[i];
            A[i+n] = a[i];  // copy second array
        }

        // Build Prefix sum of A
        vector<long long> pref(2*n+1, 0);
        for(int i=1;i<=2*n;i++) {
            pref[i] = pref[i-1] + A[i-1];
        }

        // answer queries
        while(q--) {
            long long l, r;
            cin>>l >>r;

            // convert to 0-based indexing
            long long l0 = l -1;
            long long r0 = r -1;

            long long leftblock = l0/n;
            long long rightblock = r0/n;

            long long leftindex = l0 % n;
            long long rightindex = r0 % n;

            long long ans = 0;

            if(leftblock == rightblock) {
                long long start = leftblock;  // start index in A
                ans = pref[start + rightindex + 1] - pref[start + leftindex];
            } else {
                // left sum
                long long leftsum = pref[leftblock + n] - pref[leftblock + leftindex];

                // right sum 
                long long rightsum = pref[rightblock + rightindex + 1] - pref[rightblock];

                // middle
                long long fullcount = rightblock - leftblock - 1;
                long long midsum = (fullcount > 0) ? fullcount * sum : 0;

                ans = leftsum + rightsum + midsum;
            }
            cout<< ans << "\n";
        }
    }
    return 0;
}
