Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

Solutions:

//Approaches:

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
    
    void levelOrder(TreeNode* root , unordered_map<int , vector<int>>& lookup , int level ) {
        
        //Root is not null and we have to add it to the level of the hashmap
        lookup[level].push_back(root->val) ;
        
        //Traversing through the child nodes
        if(root->left != NULL) levelOrder(root->left , lookup , level+1 ) ;
        if(root->right != NULL) levelOrder(root->right , lookup , level+1 ) ;
        
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> answer ;
        
        if(root == NULL){
            return answer;
        }
        
        //levels,numbers in that level
        unordered_map<int , vector<int>> lookup;
        int level = 0 ;
        
        levelOrder(root , lookup , level ) ;
        
        for(int i = 0 ; i < lookup.size() ; i++){
            if (i % 2 == 0){  
                answer.push_back(lookup[i]);
            }else{
                vector<int>temp = lookup[i] ;
                vector<int> array ;
                for(int i = temp.size()-1 ; i >= 0 ; i-- ){
                    array.push_back(temp[i]) ;
                }
                answer.push_back(array) ;
            }
        }
         return answer ;
    }
};
/*
[3,9,20,2,6,10,22,15,7,null,10,null,23,56,34,32,34,54,64,53,2,6,8,8,3,2,4,3,5,3,4,35,5,6,6,5,3,2,4,5,6,7,8,9,9,6,5,4,3,3,2,2,2,2,2]
*/


Time Complexity - O(N)
Space Complexity - O(N)[hashmap] + O(N)[recursive stack] - O(N)
