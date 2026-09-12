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
TreeNode* buildBST(TreeNode* root, int a ){
    if(root == nullptr){
        return  new TreeNode(a);

    }
    else{
        if(a > root->val){
            root->right = buildBST(root->right,a);
        }
        if(a < root->val){
            root ->left = buildBST(root->left,a);
        }
    }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        TreeNode* root = nullptr;
        while(i < preorder.size()){
            int a = preorder[i];
            root = buildBST(root,a);
            i++;
            
        }
        return  root;
    }
};