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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int postInd = postorder.size()-1;
        return build(inorder,postorder,postInd,0,inorder.size()-1,mp);
    }
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int& postInd,int left,int right,unordered_map<int,int>& mp){
        if(left>right) return NULL;
        TreeNode* root = new TreeNode(postorder[postInd--]);
        int inVal = mp[root->val];
        root->right = build(inorder,postorder,postInd,inVal+1,right,mp);
        root->left = build(inorder,postorder,postInd,left,inVal-1,mp);
        
        return root;
    }
};