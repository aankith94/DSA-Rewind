#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        long long n;
        cin>>n;

        if(n == 1) {
            cout<<1<<endl;
            continue;
        }
        if(n == 2) {
            cout<<9<<endl;
            continue;
        }

        long long a = n*n - n- 1;
        long long cost1 = 5*a;

        long long x = n*n - 1;
        long long cost2 = 4*x - n;

        long long ans = max(cost1, cost2);

        cout<<ans<<endl;

        
    }
    return 0;
}