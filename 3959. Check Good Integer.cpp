/*
3959. Check Good Integer
Easy

You are given a positive integer n.

Let digitSum be the sum of the digits of n, and let squareSum be the sum of the squares of the digits of n.

An integer is called good if squareSum - digitSum >= 50.

Return true if n is good. Otherwise, return false.

Example 1:

Input: n = 1000
Output: false
Explanation:
The digits of 1000 are 1, 0, 0, and 0.
The digitSum is 1 + 0 + 0 + 0 = 1.
The squareSum is 12 + 02 + 02 + 02 = 1.
The squareSum - digitSum is 1 - 1 = 0. As 0 is not greater than or equal to 50, the output is false.

Example 2:

Input: n = 19
Output: true
Explanation:
The digits of 19 are 1 and 9.
The digitSum is 1 + 9 = 10.
The squareSum is 12 + 92 = 1 + 81 = 82.
The squareSum - digitSum is 82 - 10 = 72. As 72 is greater than or equal to 50, the output is true.

Constraints:

1 <= n <= 10^9
*/

class Solution {
public:
    bool checkGoodInteger(int n) {
        int ds = 0, ss = 0, s = 0;
        while(n != 0) {
            s = n % 10;
            ds += s;
            ss += s * s;
            n /= 10;
        }
        return (ss - ds) >= 50 ? true : false;
    }
};
