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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int instart,int inend,int &preindex,unordered_map<int,int> &mp){
        if(instart>inend) return nullptr;
        //current root value
        int rootvalue=preorder[preindex++];
        TreeNode* root=new TreeNode(rootvalue);
        
        int pos=mp[rootvalue];
        root->left=helper(preorder,inorder,instart,pos-1,preindex,mp);
        root->right=helper(preorder,inorder,pos+1,inend,preindex,mp);
        return root;
        
        

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int instart=0,inend=inorder.size()-1,preindex=0;
        
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i; 
        }
        return helper(preorder, inorder, instart, inend, preindex, mp);
        
        
    }
};
