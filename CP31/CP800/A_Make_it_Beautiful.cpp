#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        // logic
        sort(a.begin(), a.end());
        if(a[0] == a[n-1]) cout<<"NO"<<endl;
        else {
            // array equal nahi hai
            cout<<"YES"<<endl;
            int l = 0, r = n-1;
            while(l <= r) {
                cout<<a[r]<<" ";
                if(l != r) {
                    cout<<a[l]<<" ";
                }
                l++;
                r--;
            }
            cout<<endl;
        }
    }
    return 0;
}