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
    void slove(TreeNode *root, vector<vector<int>> &ans, vector<int> temp,
               int count) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        count++;
        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();

            if (front == nullptr) {
                if (count % 2 == 0) {
                    reverse(temp.begin(), temp.end());
                }
                ans.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    q.push(nullptr);
                    count++;
                }
                continue;
            }
            temp.push_back(front->val);
            if (front->left != nullptr) {
                q.push(front->left);
            }
            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        vector<int> temp;
        slove(root, ans, temp, 0);
        return ans;
    }
};