/*
4. Median of Two Sorted Arrays
Hard

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        int total = nums1Size + nums2Size;
        vector<int> merged(total, 0);
        int i = 0, j = 0, k = 0;
        while (i < nums1Size && j < nums2Size) {
            if (nums1[i] <= nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        while (i < nums1Size) {
            merged[k++] = nums1[i++];
        }
        while (j < nums2Size) {
            merged[k++] = nums2[j++];
        }
        float median=0;
        if(total%2!=0)
            median = merged[total/2];
        else
            median = (merged[total/2] + merged[(total/2)-1])/2.0;

        return median;
    }
};
