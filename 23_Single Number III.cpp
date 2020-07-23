Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]

Note:

    The order of the result is not important. So in the above example, [5, 3] is also correct.
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
    
Solutions:

//Approach 1: 
-> Take a hashmap with store the value of the frequency of the occurance
-> Traverse the hashmap to find the number whose frequency is equal to 1
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     
        unordered_map<int,int> lookup ;
        for(int num : nums){
            lookup[num]++;
        }
       
        vector<int>answer ;
        for(auto onePair : lookup){
            if(onePair.second == 1){
                answer.push_back(onePair.first) ;
            }
        }
        return answer ;
    }
};
Time Complexity - O(n)[Hashmap creation] + O(n)[create annswer vector] - o(n) 
Space  Complexity - o(n) - hashmap

//Approach 2:
-> Here we are going to handle O(1) space
      XOR property :
        if both the bits are set/same then then give x^y = 0 
        if botht the bits are not set/same then give x^y = 1
        
-> First we will take the XOR of the entire array - what will be the output?
it will be the XOR of two unique numbers
Suppose the array is 1,1,2,2,3,5
XOR will be 3 ^ 5 = 6 (011 ^ 101) = (110)

-> Set bits are those bits whic are different for both the numbers.
Lets choose one bit from this result - > preferably the rightmost set bit
So if we consider all the numbers in array we can classify the numbers in two categories
1.  Group with the set bit at the chosen position
2. Group with the unset bit at the chosen position

-> IF we perform XOR of both the group the repeating numbers will cancel out each other and what we will get is two individual numbers in the separate groups

Eg: 
1 - 001
2 - 010
3 - 011
5 - 101
SUM = 011 ^ 101 = 110 (right most set bit - 010 )
Group A = 2,2,3
Group B = 1,1,5

-> It is very obvious that both the numbers will end up in different grousp as the setBit we have chosein is from their XOR and so for one of them it is set and for one of them it is unset

-> if setBit = 1 : 0000001
      setBit << 1 : 0000010
again setBit << 1 : 0000100
To check if a current bit is set, we have to perform & operation
So our XOR was 6 : 110
to find the setBit let it be 001 initially
6^setBit = (110 ^ 001) = 000 do perform setBit << 1 => setBit = 010
6^setBit = (110 ^ 010) = 010 => we got the setBit

-> now separating into the two groups and return and answer
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int sum = 0 ;
        for(int num : nums ){
            sum = sum ^ num ;
        }
        
        // ways to find the rightmost set bit
        int setBit = 1 ;
        for(int i = 0 ; i < 32 ; i++){
            if((setBit & sum) == setBit) break ;
            setBit = setBit << 1 ;
        }
        
        // ways to find the rightmost set bit
        int setBit2 = sum & -sum ;
        
        int num1 = 0 ;
        int num2 = 0 ;
        
        for(int num : nums){
            if((num & setBit2) == setBit2) num1 = num1^num ;
            else num2 = num2^num ;
        }
        return {num1,num2} ;
    }
};
Time Complexity - O(n) 
Space Complexity - O(1) - bit manipulation
