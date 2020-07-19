Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

Solutions:

//Approache1:

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
    
    void levelOrderBottom(TreeNode* root , int level , unordered_map<int , vector<int>>& map) {
       
        map[level].push_back(root->val) ;
        
        if(root->left != NULL) levelOrderBottom(root->left , level+1 , map ) ;
        if(root->right != NULL) levelOrderBottom(root->right , level+1 , map ) ;
        
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>answer ;
        unordered_map<int , vector<int>> map ;
        
        if(root == NULL) return answer ;
        
        levelOrderBottom(root , 0 , map) ;
        
        int length = map.size() - 1 ;
        for(int i = length ; i >= 0 ; i--){
            answer.push_back(map[i]) ;
        }
        return answer ;
    }
};
