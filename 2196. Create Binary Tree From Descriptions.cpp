/*
2196. Create Binary Tree From Descriptions
Medium

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

Example 1:

Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Example 2:

Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.

Constraints:

1 <= descriptions.length <= 10^4
descriptions[i].length == 3
1 <= parenti, childi <= 10^5
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
*/

#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& description) {
        unordered_map<int,TreeNode*> mp; 
        unordered_map<int,int> root;

        for(int i = 0; i < description.size(); i++){
            if(mp[description[i][0]] == 0) {
                TreeNode* temp = new TreeNode(description[i][0]);
                mp[description[i][0]] = temp;
            }

            if(mp[description[i][1]] == 0) {
                TreeNode* tem = new TreeNode(description[i][1]);
                mp[description[i][1]] = tem;
            }

            if(description[i][2] == 1) mp[description[i][0]]->left = mp[description[i][1]];
            else mp[description[i][0]]->right = mp[description[i][1]];

            if(root[description[i][0]] != -1) root[description[i][0]] = 1;
            root[description[i][1]] = -1;
        }

        int val = 0;
        for(auto &it: root) {
            if(it.second == 1) {
                val = it.first;
                break;
            }
        }
        return mp[val];
    }
};