class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* parentX = nullptr;
            TreeNode* parentY = nullptr;

            for (int i = 0; i < levelSize; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) parentX = parent;
                if (node->val == y) parentY = parent;

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            if (parentX || parentY) {
                return parentX && parentY && parentX != parentY;
            }
        }
        return false;
    }
};