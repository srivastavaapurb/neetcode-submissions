class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res){
        if(root->left) inorder(root->left,res);
        res.push_back(root->val);
        if(root->right) inorder(root->right,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inorder(root,res);
        sort(res.begin(),res.end());
        return res[k-1];
    }
};
