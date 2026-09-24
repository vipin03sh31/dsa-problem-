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
int countNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isCBT(TreeNode* root, int idx, int n){
        if(!root) return true;
        if(idx >= n) return false;
        return isCBT(root->left, 2*idx+1, n) && isCBT(root->right, 2*idx+2, n);
    }
    bool isCompleteTree(TreeNode* root) {
        int n = countNodes(root);
        return isCBT(root, 0, n);
        
    }
};