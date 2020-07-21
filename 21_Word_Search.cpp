Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

Constraints:

    board and word consists only of lowercase and uppercase English letters.
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3

Solutions:

//Approach 1:
-> Have to look through all the letter in the matrix and match it with the first word -> If this is done then only move forward
-> increase the pointer and check for the whole word
-> The value of the pointer is 0 then we have to check for that pointer value => decrease the value for it in the base case 
-> setting the current letter as '#' so that we do not come back to it again 
-> Looking for the next letter in all the directions 
-> First checking if it is inBound and then checking if it is mataching letter
-> IMP-> we do not send the direct reseult of the checkword here it, if true so true else false because it will correct answer for true but when the false will be the result, then that will be send and then we will not be able to reset the value of the letter back to the original value
-> This concludes that we will have to keep it inside if and send the answer only if it true
and if it is false then let it fall through and reach the last statement of reset and then return false
-> if everything goes correctly => we will get the answer 

class Solution {
    //left,top,right,bottom
    vector<vector<int>>directions{{0,-1},{1,0},{0,1},{-1,0}} ;
    
    bool inBound(vector<vector<char>>& board, int row , int col){
        
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size() ;
    }
    
    bool checkword(vector<vector<char>>& board, string word , int pointer , int row , int col){
        
        bool answer = false ;
        
        //base case => the last letter has been reached
        if(pointer-1 == word.size()-1 && board[row][col] == word[word.size()-1] ){
            cout << "Pointer" << pointer << endl ;
            return true ;
        }
        
        // processing is required
        char temp = board[row][col] ;
        board[row][col] = '#' ;
        
        for(vector<int>dir : directions){
            
            int nrow = row+dir[0] ;
            int ncol = col+dir[1] ;
            
            if(inBound(board,nrow,ncol) 
               && board[nrow][ncol]==word[pointer]  ){
                cout << "Found" << word[pointer] << endl;
                if(checkword(board , word , pointer+1 , nrow , ncol)){
                    return true ;
                }
            }
        }
        //processing done for this particular letter all the subsequent letter are not found
        // resetting the letter
        board[row][col] = temp ;
        
        return false ;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size() ;
        int cols = board[0].size() ;
        int pointer = 0 ;
        
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                if(board[row][col] == word[pointer] 
                   && checkword(board , word , pointer+1 , row , col) == true){
                    return true ;
                }
            }
        }
        return false ;
        
    }
};

/* Test cases
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"SEE"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCB"
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"XBCB"
[["C","A","A"],["A","A","A"],["B","C","D"]]
"AAB"
[["C","A","A"],["A","A","A"],["B","C","D"]]
"AAA"
*/

Time Complexity - O(n^2) - if false and O(word) if true
Space complexity - o(word) - recursive stack
