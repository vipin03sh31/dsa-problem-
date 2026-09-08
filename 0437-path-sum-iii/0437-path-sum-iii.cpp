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
int count = 0;
void slove(TreeNode* root, int target ,long long sum,int &count){
    if(root == nullptr){
        return;
    }
    sum = sum + root->val;
    if(sum == target){
        count++;
    }
    slove(root->left,target,sum,count);
    slove(root->right,target,sum,count);
}
    int pathSum(TreeNode* root, int targetSum) {
        // Placeholder logic for path sum
        if(root == nullptr){
            return count;
        }
        slove(root,targetSum,0,count);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);

        return count;
        
    }
};