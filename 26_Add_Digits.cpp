Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Solutions:

//Approch 1 : - loops 

class Solution {
    
    int calDigitSum(int num){
        
        int sum = 0 ;
        
        while(num>0){
            sum += num%10 ;
            num /=10 ;
        }
        return sum ;
    }
    
public:
    int addDigits(int num) {
        
        while(num > 9){
            
            num = calDigitSum(num) ;
        }
        
        return num ;
        
    }
};
Time Complexity - O(logn)
  
//Approach 2: //using maths

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0 ;
        if(num%9 == 0) return 9 ;
        return num%9 ;
    }
};
Time Complexity - O(1)
