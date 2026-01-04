/*
1390. Four Divisors
Medium

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Example 2:

Input: nums = [21,21]
Output: 64

Example 3:

Input: nums = [1,2,3,4,5]
Output: 0

Constraints:

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5
*/

#include <vector>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ts = 0, s = 0, c = 0;
        for(int num: nums){
            c = 0;
            ts = 0;
            for(int j = 1; j <= num/j; j++){
                if(num % j == 0){
                    if(j == num/j){
                        c++;
                        ts += j;
                    } else {
                        c+= 2;
                        ts += (j + num/ j);
                    }
                }
                if(c > 4) break;
            }
            if(c==4){
                s += ts;
            }
        }
        return s;
    }
};