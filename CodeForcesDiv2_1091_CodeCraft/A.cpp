#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        int k;
        cin>>n >>k;

        int sum = 0;

        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
            sum += a[i];
        }

        // code
        if(sum % 2 != 0 || (n * k) % 2 == 0) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}