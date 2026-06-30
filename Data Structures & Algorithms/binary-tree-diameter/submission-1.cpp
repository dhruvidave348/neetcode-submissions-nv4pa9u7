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
    int best=0;
    int height(TreeNode* root){
        
        if(root==nullptr) return 0;
        int leftdepth=height(root->left);
        int rightdepth=height(root->right);
        best=max(leftdepth+rightdepth,best);

        return max(leftdepth,rightdepth)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return best;


        
    }
};
