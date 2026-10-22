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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans=0;
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = 0;
            for(int i =0;i<n;i++){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                unsigned long long ind = p.second - first;

                last = ind;
                if(node->left) q.push({node->left,2*ind+1});
                if(node->right) q.push({node->right,2*ind+2});
            }
           ans = max(ans,last+1); 
        }
        return (int)ans;
    }
};