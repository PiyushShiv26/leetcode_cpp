/*
3908. Valid Digit Number
Easy

You are given an integer n and a digit x.

A number is considered valid if:

It contains at least one occurrence of digit x, and
It does not start with digit x.
Return true if n is valid, otherwise return false.

Example 1:

Input: n = 101, x = 0
Output: true
Explanation:
The number contains digit 0 at index 1. It does not start with 0, so it satisfies both conditions. Thus, the answer is true​​​​​​​.

Example 2:

Input: n = 232, x = 2
Output: false
Explanation:
The number starts with 2, which violates the condition. Thus, the answer is false.

Example 3:

Input: n = 5, x = 1
Output: false
Explanation:
The number does not contain digit 1. Thus, the answer is false.

Constraints:

0 <= n <= 10^5​​​​​​​
0 <= x <= 9
*/

class Solution {
public:
    bool validDigit(int n, int x) {
        int num = n;
        bool valid = false;
        while(num>=10){
            int r = num % 10;
            if(r == x) valid = true;
            num = num / 10;
        }
        if(num == x) valid = false;
        return valid;
    }
};