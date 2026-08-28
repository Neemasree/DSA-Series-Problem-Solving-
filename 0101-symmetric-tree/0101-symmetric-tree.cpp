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
    bool check(TreeNode* left,TreeNode* right){
         //both left and right are null,so anyways they are symmetric
        if(left==NULL && right==NULL)return true;
        //if either one is null,it is not a mirror
        if(left==NULL || right==NULL)return false;
        //check values
        if(left->val!=right->val)return false;
        //check lefts left and rights right,then lefts right and rights left
        return check(left->left,right->right)
            && check(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        //whole tree returns nothing
        if(root==NULL){
            return true;
        }
       return check(root->left,root->right);
    }
};