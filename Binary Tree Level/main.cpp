#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct LevelNode{
    int level;
    TreeNode* node;
    LevelNode(TreeNode* node, int level=0):node(node),level(level){};
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > view;
        if(root == nullptr) return view;
        
        std::queue<LevelNode> q;
        q.push(LevelNode(root));
        while(!q.empty()){
            LevelNode cur = q.front();
            q.pop();
            int level = cur.level;
            if(level == view.size()){
                view.push_back(std::vector<int>(1,cur.node->val));
            } else
                view[level].push_back(cur.node->val);
            
            if(cur.node->left != nullptr)
                q.push(LevelNode(cur.node->left, level+1));
            if(cur.node->right != nullptr)
                q.push(LevelNode(cur.node->right, level+1));
        }
        
        return view;
        
    }
};