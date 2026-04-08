#include<bits/stdc++.h>
using namespace std;

int removingDigits(int n) {
    vector<int> t(n+1, 1e9);
    
    t[0] = 0;

    // fill the rest one
    for(int i=1;i<n+1;i++) {
        string temp = to_string(i);
        for(char c : temp) {
            int d = c - '0';

            if(d > 0) t[i] = min(t[i], 1 + t[i-d]);
        }
    }

    return t[n];
}

int main() {
    int n;
    cin >> n;

    cout<<removingDigits(n);

    return 0;
}