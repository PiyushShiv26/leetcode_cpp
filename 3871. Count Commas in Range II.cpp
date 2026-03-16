/*
3871. Count Commas in Range II
Medium

You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.

Example 1:

Input: n = 1002
Output: 3
Explanation:
The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

Example 2:

Input: n = 998
Output: 0
Explanation:
​​​​​​​All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

Constraints:

1 <= n <= 10^15
*/

class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0, p;
        for (p = 1000; p <= n; p *= 1000)
            res += (n - p + 1);
        return res;
    }
};