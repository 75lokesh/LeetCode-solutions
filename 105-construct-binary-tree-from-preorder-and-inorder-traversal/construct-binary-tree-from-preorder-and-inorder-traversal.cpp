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
    TreeNode* helper(vector<int>&preorder, int start, int end){
        if(start>end) return NULL;
        int nodeval = preorder[index++];
        TreeNode* root = new TreeNode(nodeval);
        int mid = m[nodeval];
        root->left = helper(preorder,start,mid-1);
        root->right = helper(preorder,mid+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++){
            m[inorder[i]]=i;
        }
        return helper(preorder,0, n-1);
    }
};