/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void slove(TreeNode* root, long long target, long long currSum, unordered_map<long long,int>& prefixCount, int& count){
        if(root == nullptr){
            return;
        }
        currSum += root->val;

        if(prefixCount.find(currSum - target) != prefixCount.end()){
            count += prefixCount[currSum - target];
        }

        prefixCount[currSum]++;

        slove(root->left, target, currSum, prefixCount, count);
        slove(root->right, target, currSum, prefixCount, count);

        prefixCount[currSum]--; // backtrack: remove this path's contribution before returning to parent
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> prefixCount;
        prefixCount[0] = 1; // empty prefix, handles paths starting at root
        int count = 0;
        slove(root, targetSum, 0, prefixCount, count);
        return count;
    }
};