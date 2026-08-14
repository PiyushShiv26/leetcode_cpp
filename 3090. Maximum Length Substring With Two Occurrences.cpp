/*
3090. Maximum Length Substring With Two Occurrences
Easy

Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.

Example 1:

Input: s = "bcbbbcba"
Output: 4
Explanation:
The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

Example 2:

Input: s = "aaaa"
Output: 2
Explanation:
The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.
*/

#include <string>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen = 0;
        int freq[26] = {0};
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            while(freq[s[i] - 'a'] > 2){
                freq[s[j] - 'a']--;
                j++;
            }
            maxlen = max(maxlen, i - j + 1);
        }
        return maxlen;
    }
};
