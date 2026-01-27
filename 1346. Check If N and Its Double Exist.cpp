/*
1346. Check If N and Its Double Exist
Easy

Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.

Constraints:

2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i = 0; i < arr.size() - 1; i++){
            for(int j = i + 1; j < arr.size(); j++){
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) return true;
            }
        }
        return false;
    }
};