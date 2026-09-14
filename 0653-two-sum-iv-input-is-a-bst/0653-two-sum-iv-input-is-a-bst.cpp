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
bool checkTwoSum(vector<int>inorder,int k){
    int s = 0;
    int e = inorder.size()-1;
    while(s<e){
        int sum = inorder[s] + inorder[e];
        if(sum == k ){
            return true;
        }
        else if(sum > k){
            e--;
        }
        else{
            s++;
        }
    }
    return false;
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        slove(root,inorder);
        return checkTwoSum(inorder,k);
        
    }
};