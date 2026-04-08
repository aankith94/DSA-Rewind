#include<bits/stdc++.h>
using namespace std;

bool chek(int m, int x) {
    return m >= x;
}

int lowerBound(vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();  // for upper bound

    while(low <= high) {
        int mid = low + (high - low)/2;

        if(chek(arr[mid], x)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid +1;
        }
    }

    return ans + 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>> n >> k;

    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    while(k--) {
        int x;
        cin>>x;

        // This is a Lower Bound Problem
        // we have to find first element > x

        
        cout<<lowerBound(arr, x)<<endl;
    }
    return 0;
}