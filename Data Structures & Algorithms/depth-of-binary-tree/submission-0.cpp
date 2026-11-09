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
private:
    int ht(TreeNode* node){
        if(!node) return 0;
        return 1+max(ht(node->left),ht(node->right));
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int lh=ht(root->left);
        int rh=ht(root->right);
        return 1+max(lh,rh);
    }
};
