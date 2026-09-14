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
void inorderTraversal(TreeNode*root,vector<int>&inorder){
    if(root == nullptr){
        return;
    }
    inorderTraversal(root->left,inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right,inorder);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Placeholder for range sum logic
        vector<int>inorder;
        inorderTraversal(root,inorder);
        int l = 0;
        int h = inorder.size()-1;
        while( inorder[l] < low){
            l++;
        }
        while( inorder[h] > high){
            h--;
        }
        // if(h < 0 || l >= inorder.size()){
        //     return 0;
        // }
        int sum = 0;
        for(int i = l; i <= h ; i++){
            sum = sum + inorder[i];

        }
        return sum; // User to implement actual logic
    }
};