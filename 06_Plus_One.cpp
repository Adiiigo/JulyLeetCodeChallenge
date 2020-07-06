Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Hidden constraint: the array can be as big as possible which might not be able to fit in either int or long long

Solutions:

//Approach 1:
-> convert vertor into number(first tried with int and then with long long)
-> add one to it
-> convert number to vector
-> out of bound memeory error for both int and long long  
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
     
        vector<int> answer ;
        int length = digits.size() ;
        long long number = 0 ;
        long long tens = 1 ;
        for(int i = length-1 ; i >= 0 ; i-- ){
            number = number + digits[i]*tens;
            tens *= 10 ;
        }
        cout << number ; 
        number++ ;
        
        while(number > 0){
            answer.push_back(number%10) ;
            number /= 10 ;
        }
        reverse(answer.begin() , answer.end()) ;
        return answer ;
    }
};

//Approach 2:

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
     
        int length = digits.size() ;

        for(int i = length-1 ; i >= 0 ; i-- ){
            //if the ones digit is less than 9
            if(digits[i] < 9){
                digits[i]++ ;
                return digits ;
            }
            
            //it came here => ones digits is 9
            digits[i] = 0 ;
        }
        
        // came here => numbers are like 9, 99 , 999
       digits.push_back(1) ;
       reverse(digits.begin() , digits.end()) ;
       return digits; 
    }
};
