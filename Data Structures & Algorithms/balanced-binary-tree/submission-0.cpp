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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int lh=ht(root->left);
        int rh=ht(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};
