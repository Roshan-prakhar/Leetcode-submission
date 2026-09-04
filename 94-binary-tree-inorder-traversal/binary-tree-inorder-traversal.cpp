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
    TreeNode* findRightMostNode(TreeNode* node,TreeNode* par)
    {
        while(node->right!=nullptr && node->right!=par)
        {
            node=node->right;
        }
        return node;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //right me jane se phle print kro
        if(root==nullptr) return {};
        vector<int>ans;
        TreeNode* curr=root;
        
        while(curr!=nullptr)
        {
            if(curr->left!=nullptr)
            {
                TreeNode* rightnode=findRightMostNode(curr->left,curr);
                if(rightnode->right==nullptr) 
                {
                    rightnode->right=curr;
                    curr=curr->left;
                }
                else
                {  
                    rightnode->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        
        return ans;
    }
};