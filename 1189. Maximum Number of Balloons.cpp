/*
1189. Maximum Number of Balloons
Easy

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:

Input: text = "nlaebolko"
Output: 1

Example 2:

Input: text = "loonbalxballpoon"
Output: 2

Example 3:

Input: text = "leetcode"
Output: 0

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.

Note: This question is the same as 2287: Rearrange Characters to Make Target String.
*/

#include <string>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for(char ch: text) {
            if(ch == 'b') b++;
            else if(ch == 'a') a++;
            else if(ch == 'l') l++;
            else if(ch == 'o') o++;
            else if(ch == 'n') n++;
        }
        o /= 2;
        l /= 2;
        return min(min(min(min(b, a), l), o), n);
    }
};
