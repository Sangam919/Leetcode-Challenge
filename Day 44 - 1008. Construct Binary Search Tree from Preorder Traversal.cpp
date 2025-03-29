class Solution {
public:
    int x ;
    TreeNode*solve(vector<int>& preorder,int mn, int mx){
         if(x>=preorder.size())
            return NULL;
        int curr = preorder[x];
        if(curr>=mn && curr<=mx){
            TreeNode* root = new TreeNode(curr);
            x++;
            root->left = solve(preorder,mn,curr);
            root->right = solve(preorder,curr,mx);
            return root;
        } 
        return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        x=0;
        return solve(preorder,INT_MIN, INT_MAX);
    }
};
