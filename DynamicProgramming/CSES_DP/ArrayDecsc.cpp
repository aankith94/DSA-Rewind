#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int countArrayDescription(int n, int m, vector<int>& arr) {
    for(int i=0;i<n;i++) {
        if(arr[i] == 0) {
            
        }
    }
}

int main() {
    int n, m;
    cin>> n >> m;

    vector<int> arr(n);

    for(int i=0;i<n;i++) {
        cin>>arr[i];    // value 0 denotes the unknown value
    }

    cout<<countArrayDescription(n, m, arr);

    return 0;

}