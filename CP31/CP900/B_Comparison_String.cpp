#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        string s;
        cin>>s;

        // ans = longest substring of same character + 1
        int counter = 1;  // current lonest
        int longest_ans = 1;
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) {
                counter++;
            } else {
                longest_ans = max(longest_ans, counter);
                counter = 1;
            }
        }

        longest_ans = max(longest_ans, counter);

        cout<< longest_ans + 1<<endl;
    }
}