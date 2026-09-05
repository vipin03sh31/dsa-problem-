/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void slove(TreeNode* root, vector<int>& ans, int& number) {
        number = number * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(number);
        } else {
            if (root->left != nullptr) {
                slove(root->left, ans, number);
            }
            if (root->right != nullptr) {
                slove(root->right, ans, number);
            }
        }

        number = number / 10;
    }


    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if(root == nullptr){
            return sum;
        }
        vector<int> ans;
        int number = 0;
        slove(root, ans, number);
        for (int x : ans) {
            sum += x;
        }
        return sum;
    }
};