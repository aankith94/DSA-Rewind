#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int n;    // number of rows
        cin>> n;

        int m = 4;   // number of column

        vector<string> note(n);

        for(int i=0;i<n;i++) {
            cin >> note[i];
        }

        // result  -- we ave to return the column number
        vector<int> ans;

        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(note[i][j] == '#') {
                    ans.push_back(j+1);  // 0-based indexing
                    break;
                }
            }
        }

        // print the result
        for(int v : ans) {
            cout<< v<< " ";
        }

        cout<<endl;

    }
}