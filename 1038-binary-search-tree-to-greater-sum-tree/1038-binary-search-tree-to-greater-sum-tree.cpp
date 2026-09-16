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
void relpace(TreeNode*root,vector<int>inorder,int &index){
    if(root == nullptr){
        return;
    }
    relpace(root->left,inorder,index);
    root->val = inorder[index];
    index++;
    relpace(root->right,inorder,index);

}
    TreeNode* bstToGst(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        if(root->left == nullptr && root->right == nullptr){
            return root;
        }
        vector<int>inorder;
        slove(root,inorder);

        for(int i = inorder.size()-2;i>=0;i--){
            inorder[i] = inorder[i] + inorder[i+1];
        }
        int index = 0;

        relpace(root,inorder,index);
        return root;

        
    }
};