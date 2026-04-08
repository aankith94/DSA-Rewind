#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<long long> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        vector<long long> b;
        vector<long long> c;

        sort(a.begin(), a.end());
        
        int mn = a[0];
        for(int i=0;i<n;i++) {
            if(a[i] == mn) {
                b.push_back(a[i]);
            } else {
                c.push_back(a[i]);
            }
        }

        if(b.empty() || c.empty()) {
            cout<<-1<<endl;
        } else {
            cout<<b.size()<<" "<<c.size()<<endl;
            for(long long x : b) {
                cout<<x<<" ";
            }
            cout<<endl;
            for(long long y : c) {
                cout<<y<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}