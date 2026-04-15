///Variation 1 -  Count all the (i,j) Pairs such that b[i] + b[j] == k (count of such pairs.) [i<j]  ///

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int countPairs(vector<int> nums , int k) {
    int cnt = 0;
    int n = nums.size();

    unordered_map<int , int> mp;  // map is used as a freq count

    for(int i=0;i<n;i++) {
        // we b[i] + b[j] = k
        if(mp.find(k - nums[i]) != mp.end()) {
            cnt += mp[k - nums[i]];  // add frequency of that complimented element
        }
        mp[nums[i]]++;
    }
    return cnt;
}



/// Variation 2 - Count All ((i,j) pairs such that b[i] - b[j] == k (count of such pairs.) [i<j] ///

int countPairs(vector<int> nums , int k) {
    int cnt = 0;
    int n = nums.size();

    unordered_map<int , int> mp;  // map is used as a freq count

    for(int i=0;i<n;i++) {
        // we b[i] + b[j] = k
        if(mp.find(k + nums[i]) != mp.end()) {
            cnt += mp[k + nums[i]];  // add frequency of that complimented element
        }
        mp[nums[i]]++;
    }
    return cnt;
}



/// Variation 3 - Count all i,j pairs where i<j and abs(b[i]-b[j]) = k [k>=0]  ///

int countPairs(vector<int> nums , int k) {
    int cnt = 0;
    int n = nums.size();

    unordered_map<int , int> mp;  // map is used as a freq count

    for(int i=0;i<n;i++) {
        // we b[i] - b[j] = k
        if(mp.find(nums[i] - k) != mp.end()) {
            cnt += mp[k + nums[i]];  // add frequency of that complimented element
        }
        if(k != 0 && mp.find(nums[i] + k) != mp.end()) {  // k = 0 double count occurs so k != 0
            cnt += mp[nums[i] + k];
        }
        
        mp[nums[i]]++;
    }
    return cnt;
}



int main() {
    std::vector<int> arr = {1, 5, 3, 4,2};
    int k = 2;
    std::cout << "Count of pairs: " << countPairs(arr, k) << std::endl;
    return 0;
}