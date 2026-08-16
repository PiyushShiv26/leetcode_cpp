/*
4021. Minimum Operations to Make a Rotated Palindrome I
Medium

You are given a string s consisting of lowercase English letters.

You can perform the following operations any number of times (including zero) and in any order:

Increment: Choose any index i and replace s[i] with the next lowercase English letter. The letter after 'z' is 'a'.
Left rotate: Move the first character of the string to the end.
Return the minimum number of operations required to make s a palindrome.

Example 1:

Input: s = "abc"
Output: 2
Explanation:
One optimal solution:
Left rotate the string: "abc" -> "bca".
Increment 'a' to 'b': "bca" -> "bcb".
"bcb" is a palindrome. Thus, the answer is 2.

Example 2:

Input: s = "yb"
Output: 3
Explanation:
Increment the first character three times: "yb" -> "zb" -> "ab" -> "bb".
"bb" is a palindrome. Thus, the answer is 3.

Constraints:

2 <= s.length <= 2000
s consists only of lowercase English letters.
*/

#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int mintot = INT_MAX;

        for(int i = 0; i < n; i++) {
            int curr = i;

            for(int j = 0; j < n / 2; j++) {
                char c1 = s[(i + j) % n];
                char c2 = s[(i + n - 1 - j) % n];

                int diff1 = (c2 - c1 + 26) % 26;
                int diff2 = (c1 - c2 + 26) % 26;

                curr += min(diff1, diff2);
            }
            mintot = min(mintot, curr);
        }
        return mintot;
    }
};
