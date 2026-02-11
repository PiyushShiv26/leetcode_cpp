/*
128. Longest Consecutive Sequence
Medium

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int,int>mp;
      int maxLen = 0;
      for(int num:nums){
        if(!mp[num]){
            mp[num] = mp[num-1]+mp[num+1]+1;
            mp[num-mp[num-1]] = mp[num];
            mp[num+mp[num+1]] = mp[num];
            maxLen = max(maxLen,mp[num]);
        }
      }
      return maxLen ; 
    }
};