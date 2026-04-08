// 6.  Find Sum of Range  [l……….r] where(l<=r) using Prefix sum. ///

// Sum[l, r] = pref[r] - pref[l-1]
// pref[i] = pref[i-1] + nums[i]

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> prefixSum(vector<int> nums ) {
    int n = nums.size();
    vector<int> prefix(n+1, 0);

    for(int i=1;i<=n;i++) {
        prefix[i] = prefix[i-1] + nums[i];
    }
    return prefix;
}

int optimizedSum(vector<int>& prefix, int l, int r) {
    return prefix[r] - prefix[l-1];
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> prefix = prefixSum(nums);
 
    int l = 3, r = 7; // Example range [l, r]
    cout << "Optimized Sum: " << optimizedSum(prefix, l, r) << endl;
 
    return 0;
}
 