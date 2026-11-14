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
    int index = 0;
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        index = n - 1;
        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return helper(postorder, 0, n-1);
    }
    TreeNode* helper(vector<int>& postorder, int s, int e) {
        if (s > e) {
            return NULL;
        }
        int val = postorder[index--];
        TreeNode* node = new TreeNode(val);
        int mid = m[val];
        node->right = helper(postorder, mid + 1, e);
        node->left = helper(postorder, s, mid - 1);
        return node;
    }
};