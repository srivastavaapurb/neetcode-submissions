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
bool f(TreeNode* root, int lower, int upper){
    if(!root) return true;
    if(root->val <= lower || root->val >= upper) return false;
    return f(root->left,lower,root->val) && f(root->right,root->val,upper);
}
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return f(root,INT_MIN,INT_MAX);
    }
};
