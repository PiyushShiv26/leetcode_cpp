/*
349. Intersection of Two Arrays
Easy

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>s(arr1.begin(),arr1.end());
        vector<int>v;
        for(int i:arr2){
            if(s.erase(i)) v.push_back(i);
        }
        return v;
    }
};