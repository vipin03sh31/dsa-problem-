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
void slove(TreeNode* root, vector<int>&inorder){
    if(root == nullptr){
        return;
    }
    slove(root->left,inorder);
    inorder.push_back(root->val);
    slove(root->right,inorder);
}
TreeNode *build(vector<int> &nums, int lo, int hi) {
        if (lo > hi)
            return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, lo, mid - 1);
        root->right = build(nums, mid + 1, hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        slove(root,inorder);
        if (inorder.empty())
            return nullptr;
        return build(inorder, 0, inorder.size() - 1);
        
    }
};