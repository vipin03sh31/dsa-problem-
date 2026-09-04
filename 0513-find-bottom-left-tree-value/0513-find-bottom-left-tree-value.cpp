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
void slove(TreeNode* root, vector<int>& ans, int depth){
	    if(root == nullptr){
	        return;
	    }
	    if(depth == ans.size()){
	        ans.push_back(root->val);
	    }
        
	    slove(root->left, ans, depth+1);
        slove(root->right, ans, depth+1);
	    
	}
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
		slove(root, ans, 0);
        int a = ans[ans.size()-1];
		return a;
        
        
    }
};