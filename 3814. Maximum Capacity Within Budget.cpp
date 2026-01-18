/*
3814. Maximum Capacity Within Budget
Medium

You are given two integer arrays costs and capacity, both of length n, where costs[i] represents the purchase cost of the ith machine and capacity[i] represents its performance capacity.

You are also given an integer budget.

You may select at most two distinct machines such that the total cost of the selected machines is strictly less than budget.

Return the maximum achievable total capacity of the selected machines.

Example 1:

Input: costs = [4,8,5,3], capacity = [1,5,2,7], budget = 8
Output: 8
Explanation:
Choose two machines with costs[0] = 4 and costs[3] = 3.
The total cost is 4 + 3 = 7, which is strictly less than budget = 8.
The maximum total capacity is capacity[0] + capacity[3] = 1 + 7 = 8.

Example 2:

Input: costs = [3,5,7,4], capacity = [2,4,3,6], budget = 7
Output: 6
Explanation:
Choose one machine with costs[3] = 4.
The total cost is 4, which is strictly less than budget = 7.
The maximum total capacity is capacity[3] = 6.

Example 3:

Input: costs = [2,2,2], capacity = [3,5,4], budget = 5
Output: 9
Explanation:
Choose two machines with costs[1] = 2 and costs[2] = 2.
The total cost is 2 + 2 = 4, which is strictly less than budget = 5.
The maximum total capacity is capacity[1] + capacity[2] = 5 + 4 = 9.

Constraints:

1 <= n == costs.length == capacity.length <= 105
1 <= costs[i], capacity[i] <= 105
1 <= budget <= 2 * 105
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int, int>>v;

        for(int i = 0; i < n; i++) {
            v.push_back({costs[i], capacity[i]});
        }

        sort(v.begin(), v.end());

        vector<int> pre(n);
        pre[0] = v[0].second;
        for(int i = 1; i < n; i++){
            pre[i] = max(pre[i-1], v[i].second);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int rem = budget - v[i].first;
            if(rem<=0) continue;

            ans = max(ans, v[i].second);

            int low = 0, high = i-1, ind = -1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(v[mid].first < rem){
                    ind = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if(ind != -1) {
                ans = max(ans, v[i].second + pre[ind]);
            }
        }

        return ans;
    }
};