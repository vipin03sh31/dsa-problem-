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
void slove(TreeNode* root, TreeNode*prev,int &count){
    if(root == nullptr){
        return ;
    }
    if(root->val >= prev->val){
        count++;
        prev =  root;
    }
    slove(root->left,prev,count);
    slove(root->right,prev,count);

}
    int goodNodes(TreeNode* root) {
        int count = 0;
        TreeNode*prev = root;
        slove(root,prev,count);
        //slove(root->right,prev,count);

        return count;

        
    }
};