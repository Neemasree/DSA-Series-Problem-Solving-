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
public:
    int maxi=0;
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int ls=height(root->left);
        int rs=height(root->right);
        return 1+max(ls,rs);
    }
    void diameter(TreeNode* root){
        if(root==NULL)return;
        int ls=height(root->left);
        int rs=height(root->right);
        maxi=max(maxi,ls+rs);
        diameter(root->left);
        diameter(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxi;
    }
};