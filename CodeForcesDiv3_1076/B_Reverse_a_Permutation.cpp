#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    long long t;
    cin>>t;

    while(t--) {
        long long n;
        cin>>n;

        vector<long long> p(n);
        for(int i=0;i<n;i++) {
            cin>>p[i];
        }

        // solve it
        int i = 0;
        while(i < n && p[i] == n-i) i++;// it should find 
        
        // if alredy sorted
        if(i == n) {
            for(long long x : p) cout << x << " ";
            
            cout << "\n";
            continue;
        }


        // find j such that p[j] == n - i
        int j = i;
        while(j < n && p[j] != n - i) {
            j++;
        }// j is also found

        reverse(p.begin() + i, p.begin() + j + 1);

        for(int x : p) cout << x << " ";
            cout << "\n";
        }
    return 0;
}