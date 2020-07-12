Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Solutions:

//Approach 1:
-> using bit masking.
-> created all the possibles binary representations and correspondingly generating the subsets
-> this was is simple and ensures that all the possibles subsets are created
-> the problem arises to create numbers with leading zeroes, this can be solved by creating numbers from 2^n to 2^(n+1) and trimming the first msb
-> The code explains the rest

class Solution {
    
    vector<int> calBinary(int num){
        
        vector<int> answer ;
        while(num > 0){
            // cout << num%2 ;
            answer.push_back(num%2) ;
            num /= 2 ;
        }
        reverse(answer.begin() , answer.end()) ;
        return answer ;
    }
    
    vector<int> calTrim(vector<int> num){
        
        vector<int> answer ;
        int length = num.size() ;
        
        for(int i = 1 ; i < length ; i++){
            answer.push_back(num[i]) ;
        }
        return answer ;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        
        int length = nums.size() ;
        int startpow = pow(2,length) ;
        int endpow = pow(2,length+1) ;
        
        for(int i = startpow ; i < endpow ; i++){
            
            vector<int>binaryi = calBinary(i) ; //this is calculate binary
            vector<int>finali = calTrim(binaryi) ; //this will trim the first msb 
            
            vector<int> curanswer ;
            for(int j = 0 ; j < length ; j++){
                if(finali[j] == 1) curanswer.push_back(nums[j]) ;
            }
            answer.push_back(curanswer) ;
        }
        return answer ;
    }
};
