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
void slove(TreeNode* root, int &mina, TreeNode* &prev){
    if(root == nullptr){
        return;
    }
    slove(root->left, mina, prev);
    if(prev != nullptr){
        mina = min(mina, abs(root->val - prev->val));
    }
    prev = root;
    slove(root->right, mina, prev);
}
    int minDiffInBST(TreeNode* root) {
        int mina = INT_MAX;
        TreeNode* prev = nullptr;
        slove(root, mina, prev);
        return mina;
    }
};