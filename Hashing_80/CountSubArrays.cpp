// 7. Find count of number of subarrays with sum ==  k

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// we have to count no of subarrays with sum = k  
// one metod is tat maintain a prefixsum array and find sum - k

// More Optimized Approac - PrefixSum + Hasing
int countSubArrayOptimized(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumCount;

    int sum = 0;
    int count = 0;

    prefixSumCount[0] = 1;  // if we include all elements then count must be 1

    for(int num : arr) {
        sum += num;

        if(prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            // found it
            count += prefixSumCount[sum - k];
        }

        prefixSumCount[sum] ++;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Number of subarrays with sum " << k << ": " << countSubArrayOptimized(arr, k) << endl;
    return 0;
}

// Now Variation 2 - Find largest/smallest subarray with sum k in Given Array

// idea is simple - Maintain a prefixSum hashmap for tracking where the p[j] - k occurs first time(largest) and last time(smallest)

// Larest

// unordered_map<int, int> mp;
// mp[0] = 1;  // takes all

// int prefix = 0;
// int maxLen = 0;

// for(int j=0;j<n;j++) {
//     prefix += arr[j];

//     if(mp.find(prefix - k) != mp.end()) {
//         int i = mp[prefix - k];  // occurence
//         maxLen = max(maxLen, j - i);
//     }

//     // store only first occurence
//     if(mp.find(prefix) == mp.end()) {
//         mp[prefix] = j;
//     }
// }


// // smallest
// unordered_map<int, int> mp;
// mp[0] = -1;

// int prefix = 0;
// int minLen = INT_MAX;

// for(int j = 0; j < n; j++) {
//     prefix += a[j];

//     if(mp.find(prefix - k) != mp.end()) {
//         int i = mp[prefix - k];
//         minLen = min(minLen, j - i);
//     }

//     // overwrite to keep latest occurrence
//     mp[prefix] = j;
// }



// Variation 3 - Find count of shortest/largest subarrays with sum k in given array
// Hashing + PrefixSum + SlidingWindow
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

pair<int, int> findSubarraySizes(int n, int k, const vector<int>& arr) {
    unordered_map<int, int> mp;
    unordered_map<int, int> mp2;
    mp[0] = 0;
    int pSum = 0;
    int maxLength = 0;
    int minLength = INT_MAX;

    for (int j = 1; j <= n; j++) {
        pSum += arr[j - 1];
        int x = pSum - k;

        if (mp.find(x) != mp.end()) {
            int i = mp[x] + 1;
            int curLength = j - i + 1;
            if (curLength > maxLength) {
                maxLength = curLength;
            }
        }

        if (mp2.find(x) != mp2.end()) {
            int i = mp2[x] + 1;
            int curLength = j - i + 1;
            if (curLength < minLength) {
                minLength = curLength;
            }
        }

        if (mp.find(pSum) == mp.end())
            mp[pSum] = j;

        mp2[pSum] = j;
    }

    return {maxLength, minLength};
}

int countSubarraysWithLength(int n, int k, const vector<int>& arr, int targetLength) {
    if (targetLength == 0) return 0;
    int count = 0;
    int windowSum = 0;

    for (int j = 0; j < targetLength; j++) {
        windowSum += arr[j];
    }

    if (windowSum == k) {
        count++;
    }

    for (int j = targetLength; j < n; j++) {
        windowSum += arr[j] - arr[j - targetLength];
        if (windowSum == k) {
            count++;
        }
    }

    return count;
}

int main() {
    int n = 6;
    int k = 5;
    vector<int> arr = {1, 2, 3, 4, 2, 5};

    auto [maxLength, minLength] = findSubarraySizes(n, k, arr);
    int maxCount = countSubarraysWithLength(n, k, arr, maxLength);
    int minCount = countSubarraysWithLength(n, k, arr, minLength);

    cout << "Max Length: " << maxLength << " Count: " << maxCount << endl;
    cout << "Min Length: " << minLength << " Count: " << minCount << endl;

    return 0;
}



// 1 Template - 3 Variations
#include <bits/stdc++.h>
using namespace std;

struct Result {
    int count;
    int maxLen;
    int minLen;
};

Result solve(vector<int>& arr, int k) {
    unordered_map<int, int> freq;     // for count
    unordered_map<int, int> first;    // for largest
    unordered_map<int, int> last;     // for smallest

    freq[0] = 1;
    first[0] = -1;
    last[0] = -1;

    int prefix = 0;
    int count = 0;
    int maxLen = 0;
    int minLen = INT_MAX;

    for(int j = 0; j < arr.size(); j++) {
        prefix += arr[j];

        // 🔹 COUNT
        if(freq.find(prefix - k) != freq.end()) {
            count += freq[prefix - k];
        }

        // 🔹 LARGEST
        if(first.find(prefix - k) != first.end()) {
            maxLen = max(maxLen, j - first[prefix - k]);
        }

        // 🔹 SMALLEST
        if(last.find(prefix - k) != last.end()) {
            minLen = min(minLen, j - last[prefix - k]);
        }

        // update maps
        freq[prefix]++;
        
        if(first.find(prefix) == first.end())
            first[prefix] = j;

        last[prefix] = j;
    }

    if(minLen == INT_MAX) minLen = 0;

    return {count, maxLen, minLen};
}