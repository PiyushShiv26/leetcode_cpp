/*
2840. Check if Strings Can be Made Equal With Operations II
Medium

You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

Example 1:

Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

Example 2:

Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.

Constraints:

n == s1.length == s2.length
1 <= n <= 10^5
s1 and s2 consist only of lowercase English letters.
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string s1even="";
        string s1odd="";
        string s2even="";
        string s2odd="";

        for(int i=0;i<n;i++)
        {
            if(i%2==0){
                s1even+=s1[i];
                s2even+=s2[i];
            }else{
                s1odd+=s1[i]; 
                s2odd+=s2[i];
            }
        }
        sort(s1even.begin(),s1even.end());
        sort(s2even.begin(),s2even.end());
        sort(s1odd.begin(),s1odd.end());
        sort(s2odd.begin(),s2odd.end());

        if(s1even==s2even && s1odd==s2odd){
            return true;
        }

        return false;
    }
};