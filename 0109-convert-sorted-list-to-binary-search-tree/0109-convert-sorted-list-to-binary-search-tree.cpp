/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *buildBSt(ListNode *head, ListNode *tail) {          // fix: now range-based, no more build() calls
        if (head == tail) return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {              // fix: find mid within [head, tail)
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = buildBSt(head, slow);                         // fix: recurse instead of insert loop
        root->right = buildBSt(slow->next, tail);                  // fix: recurse instead of insert loop
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        return buildBSt(head, nullptr);                            // fix: single call, no separate slow/fast here
    }
};