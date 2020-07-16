Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]

Solutions:

//Approaches 1 - Linear multiplcation
-> In this multiplication is happening by continously multiplying the number by the multiplicand
-> If the power is negative that we just multiply the number and reciprocate the number 

class Solution {
public:
    double myPow(double x, int n) {
        int multiplier = abs(n) ;
        double answer = 1 ;
        
        for(int i = 0 ; i < multiplier ; i++){
            answer = answer*x ;
        }
        
        if(n < 0){
            answer = 1 / answer ;
        }
        
        return answer ;
    }
};
Time Complexity - O(x^n)- time limit excceded - for x=1.00000 n=-2147483648
Space Complexity - O(1) since no extra space is used

//Approach 2: Using division

class Solution {
    int count = 0 ;
    
    double myPowUtil(double x , int start, int end) {
        
        if(end-start == 0){
            //only one element
            return x ;
        }
        
        if(end-start == 1){
            //only two element
            return x*x ;
        }
            
        // else need further division
        int mid = start+((end-start)/2) ;
        count = count + 2 ;
        
        return myPowUtil(x , start , mid) * myPowUtil(x , mid+1 , end) ;
        
    }
    
public:
    double myPow(double x, int n) {
        int multiplier = abs(n) ;
        double answer = 1 ;
      
        answer = myPowUtil(x,0,multiplier-1) ;
        cout << count << endl;
        if(n < 0){
            answer = 1 / answer ;
        }
        
       
        return answer ;
    }
};
Time Complexity - O(x^n)- time limit excceded - for x=1.00000 n=-2147483648
Space Complexity - O(1) since no extra space is used

//Approach 3:
-> operator precedence is really pain in the rear
-> beware of division and multiplication while n is odd

class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0){
            return 1 ;
        }
        
        double answer = 1 ;
        
        answer = myPow(x,n/2) ;
        
        if(n%2 == 0 ){
            //even numbers
            return answer*answer ;
        }
        else{
            //odd numbers
            return (n<0)?1/x*answer*answer:answer*answer*x ;
        }        
    }
};

Time Complexity - O(x log n)
Space complexity - O(1) + recusion stack

Test cases passed:
2.00000
10
2.10000
3
2.00000
-2
99.0
1024
-99.0
-1024
1.00000
-2147483648
1.00000
-2147483648
