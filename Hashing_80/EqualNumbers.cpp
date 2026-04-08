/// Check if there are any two Equal numbers in an array at a distance less than or equal to k  ///


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool isEqual(vector<int> nums , int k) {
    int n = nums.size();

    unordered_map<int, int> mp;  // we can store the last occurencxe in map

    // Using Optimized Approach
    for(int i=0;i<n;i++) {
        if(mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
            return true;

        }
        mp[nums[i]] = i;

    }

    return false;

}

int main() {
    vector<int> nums = {1, 2, 5, 4, 6, 1};
    int k = 2;
    if (isEqual(nums, k)) {
        cout << "There are two equal numbers within distance " << k << std::endl;
    } else {
        cout << "No two equal numbers found within distance " << k << std::endl;
    }
    return 0;
}
