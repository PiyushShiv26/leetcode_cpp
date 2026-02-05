/*
345. Reverse Vowels of a String
Easy

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"
Output: "leotcede"

Constraints:

1 <= s.length <= 3 * 10^5
s consist of printable ASCII characters.
*/

#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    int isvow(char a){
        char c = (char) tolower(a);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
        else return 0;
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while(l<r) {
            if(!isvow(s[l])) l++;
            else if(!isvow(s[r])) r--;
            else (swap(s[l++], s[r--]));
        }
        return s;
    }
};