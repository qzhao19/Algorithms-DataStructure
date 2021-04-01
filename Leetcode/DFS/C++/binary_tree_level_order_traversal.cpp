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
    
    // define a 2d array to store answers
    vector<vector<int>> ans;
    
    void dfs(TreeNode *node, int depth){
        
        // node: current node to traverse
        if (node == NULL){
            return ;
        }
        
        if (ans.size() == depth){
            ans.emplace_back();
        }
        // put the value of current node into ans
        ans[depth].push_back(node -> val);
        dfs(node -> left, depth + 1);
        dfs(node -> right, depth + 1); 
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        dfs(root, 0);
        return ans;
       
        
        
    }
};