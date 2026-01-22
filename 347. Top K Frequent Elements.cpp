/*
347. Top K Frequent Elements
Medium

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        vector<int> res;
        for(int i: nums){
            map[i]++;
        }
        while(k!=0){
            int max_ele = 0;
            int max_freq = 0;
            for(auto& a: map){
                if(a.second > max_freq) {
                    max_freq = a.second;
                    max_ele = a.first;
                }
            }
            res.push_back(max_ele);
            map.erase(max_ele);
            k--;
        }
        return res;
    }
};