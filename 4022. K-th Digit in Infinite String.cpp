/*
4022. K-th Digit in Infinite String
Medium

You are given an integer k.

An infinite string is formed by concatenating the decimal representations of the positive integers, without separators.

For every nonnegative integer b, block b contains the positive integers from 10 * b through 10 * b + 9. The integers in each block are appended as follows:

If b is even, append the integers in increasing order.
If b is odd, append the integers in decreasing order.
Therefore, the string starts with the integers 1 through 9, followed by 19 through 10, then 20 through 29, then 39 through 30, and so on.

Return the kth digit (1-indexed) of this string.

Example 1:

Input: k = 4
Output: 4
Explanation:
The string begins as "123456789..". The 4th digit is '4'.

Example 2:

Input: k = 15
Output: 7
Explanation:
The string begins as "123456789191817..". The 15th digit is '7'.

Example 3:

Input: k = 11
Output: 9
Explanation:
The string begins as "12345678919..". The 11th digit is '9'.

Constraints:

1 <= k <= 10^15
*/

#include <string>
using namespace std;

class Solution {
public:
    int kthDigit(long long k) {
        if(k <= 9) return k;

        k -= 10;

        long long L = 2, b = 1, levlen = 180;

        while(k >= levlen) {
            k -= levlen;
            b *= 10;
            L++;
            levlen = b * 180 * L / 2;
        }

        b += k / (10 * L);
        int rem = k % (10 * L);
        int idx = rem / L;

        long long num = 10 * b + (b % 2 == 0 ? idx : 9 - idx);
        return to_string(num)[rem % L] - '0';
    }
};
