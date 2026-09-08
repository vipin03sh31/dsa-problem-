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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<pair<TreeNode*,pair<int,int>>>q; // node, {hd, depth}
        q.push(make_pair(root,make_pair(0,0)));
        unordered_map<int,vector<pair<int,int>>> distMap; // hd -> {depth, val}
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> frontpair = q.front();
            q.pop();
            TreeNode* frontNode = frontpair.first;
            int hd = frontpair.second.first;
            int depth = frontpair.second.second;
            minDist = min(minDist,hd);
            maxDist = max(maxDist,hd);

            distMap[hd].push_back(make_pair(depth, frontNode->val));

            if(frontNode->left != nullptr){
                q.push(make_pair(frontNode->left,make_pair(hd-1,depth+1)));
            }
            if(frontNode->right != nullptr){
                q.push(make_pair(frontNode->right,make_pair(hd+1,depth+1)));
            }
        }

        vector<vector<int>>ans;
        for(int i = minDist; i<= maxDist;i++){
            vector<pair<int,int>> a = distMap[i];
            sort(a.begin(), a.end());
            vector<int> col;
            for(auto &p : a){
                col.push_back(p.second);
            }
            ans.push_back(col);
        }
        return ans;
    }
};