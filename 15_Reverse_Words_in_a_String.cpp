Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:
    A word is defined as a sequence of non-space characters.
    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
    You need to reduce multiple spaces between two words to a single space in the reversed string.

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

Solutions:

//Approach 1 : Two pointers
-> Start from the end and and keep the first pointer(i) decrementing and decrementing on the white spaces whenever we find the first letter go inside the first if statement.
-> Inside the if statement we are starting the second pointer(j) which will be used to find the whole word and break when we will find the space.
-> Since space is included increase the value of J by 1 ;
-> use the for lool to put the word in temp
-> append that to the annswer and repeat the process till the value of first pointer(i) is zero

class Solution {
public:
    string reverseWords(string s) {
         
        int i = s.size()-1 ;
        // cout << s[i-1] ;
        string answer ;
        
        while(i >= 0){
            
            if(s[i] !=' '){
                //find another letter pointer
                //append from i to j to the answer ; 
                
                int j = i ;
                for( ; j >= 0 ; j--){
                    if(s[j] == ' '){
                        break ;
                    }
                } 
                
                j++ ;
                string temp ;
                for(int k = j ; k <= i ; k++){
                    temp = temp+s[k] ;
                }
                cout << temp << endl ;
                if(answer.empty()){
                    answer = temp ;
                }
                else{
                    answer = answer + ' ' + temp ;
                }
                i = j ;

            }
            i-- ;
        }
        return answer ;
        
    }
};

Time Complexity - O(N) - traversing only once
Space Complexity - O(1) - no extra spaces is used
