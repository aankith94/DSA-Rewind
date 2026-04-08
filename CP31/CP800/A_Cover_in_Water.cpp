#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int n;
        cin>>n;

        string s;
        cin>> s;

        int dotCount = 0;
        bool threeDot = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') dotCount++;
        }

        for (int i = 0; i + 2 < n; i++) {
            if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
                threeDot = true;
                break;
            }
        }

        if (threeDot)
            cout << 2 << "\n";
        else
            cout << dotCount << "\n";
        }
}