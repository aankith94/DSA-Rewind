#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        // code here!

        bool ans = false;
        if(n == 2) {
            ans = true;
        } else {
            sort(a.begin(), a.end());
            if(a[0] + a[n-1] == a[1] + a[n-2]) {
                ans = true;
            }
        }

    }
}