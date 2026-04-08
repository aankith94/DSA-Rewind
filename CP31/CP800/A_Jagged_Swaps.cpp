#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        //code here!
        vector<int> copy_a = a;
        sort(copy_a.begin(), copy_a.end());

        if(a[0] == copy_a[0]) {
            // min is at correct place
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}