struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) 
            return nullptr;
        nodeUpdate(root);
        return root;
    }

    int nodeUpdate(TreeNode* root, int from_root = 0, bool is_left = false) {
        int right = 0;
        int left = 0;
        if(root->right != nullptr)
            right = nodeUpdate(root->right, from_root);
        else
            right = from_root;

        root->val += right;

        if(root->left != nullptr)
            left = nodeUpdate(root->left, root->val, true);
            
        return root->val + left - (is_left? from_root:0);
    }
};