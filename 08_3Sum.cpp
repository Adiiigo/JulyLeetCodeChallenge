Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

  - Hide Hint #1  
So, we essentially need to find three numbers x, y, and z such that they add up to the given value. If we fix one of the numbers say x, we are left with the two-sum problem at hand!

  - Hide Hint #2  
For the two-sum problem, if we fix one of the numbers, say
x
, we have to scan the entire array to find the next number
y
which is
value - x
where value is the input parameter. Can we change our array somehow so that this search becomes faster?

  - Hide Hint #3  
The second train of thought for two-sum is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

Solutions:

//Approach 1(Brute force):
-> using three for loops to go through the the numbers and find the sum should be equal to 0
-> Time limit exceeded for the array of large size

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end()) ;
        
        int length = nums.size() ;
        
        vector<vector<int>> answer ;
        
        for(int i = 0 ; i < length ; i++){
            
            /*
            * if we come across the number which is duplicate of the previous number 
            * implies that we can skip this element as such combo has already been considered ans
            * and triplets should haave unique numbers only
            */
            if(i > 0 && nums[i] == nums[i-1]) continue ;
                
            for(int j = i+1 ; j < length ; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue ;
                
                for( int k = j+1 ; k < length ; k++){
                    if(k > j+1 && nums[k] == nums[k-1]) continue ;
                    
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp ;
                        temp.push_back(nums[i]) ;
                        temp.push_back(nums[j]) ;
                        temp.push_back(nums[k]) ;                        
                        answer.push_back(temp) ;
                    }
                }
            }
        }
        return answer ;
    }
};

Time Complexity - O(N*N)
Space Complexity - O(1) - no extra space is used

//Approach 2 : Two pointers:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end()) ;
        
        int length = nums.size() ;
        vector<vector<int>> answer ;
        
        for(int indexA = 0 ; indexA < length-2 ; indexA++){
            
            /*
            *  This line makes a huge difference as it will skip all the numbers which start with positive number coz if we start with positive number this means
            *   after this all the number are positive and it will ve waste of time to check for further elements
            */
            
            if(nums[indexA] > 0) return answer ;
                       
            int indexB = indexA+1 ;
            int indexC = length-1 ;
            
            while(indexB < indexC){
                
                int sum = nums[indexA] + nums[indexB] + nums[indexC] ;
                
                if(sum > 0){
                    /*
                    * sum is bigger and hence remove the bigger element to make it smaller
                    */
                    indexC--;
                }
                else if(sum < 0){
                    /*
                    * sum is smaller and hence remove the smaller element to make it bigger
                    */
                    indexB++;
                }
                else{
                    /*
                    * sum is equal to zero
                    */
                    vector<int> temp ;
                    temp.push_back(nums[indexA]) ;
                    temp.push_back(nums[indexB]) ;
                    temp.push_back(nums[indexC]) ;
                    cout << nums[indexA] << nums[indexB] << nums[indexC] ;
                    answer.push_back(temp) ;
                    int num1 = nums[indexB] ;
                    int num2 = nums[indexC] ;
                    while(indexB < indexC && num1 == nums[indexB]) indexB++ ;
                    while(indexB < indexC && num2 == nums[indexC]) indexC-- ;
                }
            }
            
            while(indexA+1 < length-2 && nums[indexA] == nums[indexA+1] ) indexA++ ;
        }
        return answer ;
    }
};

Time Complexity still is O(N*N) but the processing time is reduced

References 
- https://medium.com/@paulrohan/solving-the-classic-two-sum-and-three-sum-problem-in-javascript-7d5d1d47db03
- https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments - in this the comment section answer is correct.
