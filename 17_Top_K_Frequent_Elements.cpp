Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
    It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
    You can return the answer in any order.

Solutions:

//Approache 1 : HashMap + MaxHeap
-> First we have to build hashmap (element->frequency). This step tales O(N) time where N is the number of elements
-> Second we will have to build the max Heap will have the elements in the descending order according to the occurance
-> We will remove k elements from the heap and add it to the answer vector

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>lookup ;
        vector<int> answer ;
        priority_queue<pair<int,int>> queue ;
        
        for(int num : nums){
            lookup[num]++ ;
        }
        
        for(auto i : lookup){
            queue.push({i.second , i.first}) ;
        }
        
        for(int i = 0 ; i < k ; i++){
            
            answer.push_back(queue.top().second);
            queue.pop() ;
            
        }
        
        return answer ;
    }
};
Each element is inserted in minHeap - O(H-height od the tree) - O(K)
Time Complexity - O(N[HashMap] + NlogN(insertion of N elements) + klogN(deletetion on K elements) + N[adding in the answer vector] ) - O(NlogN)
Space Complecity - O(N[hashMap] + N[minHeap]) - O(N)

//Appraoch 2: HashMap + MinHeap
-> First we have to build hashmap (element->frequency). This step tales O(N) time where N is the number of elements
-> We will only add K elements in the minHeap and it will be add accordance to the frequency of the numbers. we K elements will be add, this will ensure that the smallees occurance will at the top and we will check for the new combo id the new comba has more occurance then we will remove the least of these K occurance from the minHeap and the new highest occurance till all the elements are checked out
-> Now since we have only K elements in the minheap and we can remove them add it to the answer vector

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>lookup ;
        vector<int> answer ;
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > minHeap ;
        
        for(int num : nums){
            lookup[num]++ ;
        }
        
        class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>lookup ;
        vector<int> answer ;
        priority_queue<pair<int,int>> queue ;
        
        for(int num : nums){
            lookup[num]++ ;
        }
        
        for(auto i : lookup){
            queue.push({i.second , i.first}) ;
        }
        
        for(int i = 0 ; i < k ; i++){
            
            answer.push_back(queue.top().second);
            queue.pop() ;
            
        }
        
        return answer ;
    }
};
        
        
        for(auto i : lookup){
            
            if(minHeap.size() < k){
                // insert the first k elements in the minHeap
                minHeap.push({i.second , i.first}) ;
            }
            else{
                //minHeap is full and we will only update the heap now
                
                int numOccu =minHeap.top().first ;
                int realNum = minHeap.top().second ;
                
                // here top element is the smallest and all the other elements will obviously be less
                // so we will have to remove the least frequent in the tree and add the current combo in the                        minHeap
                if(i.second > numOccu ){
                    minHeap.pop() ;
                    minHeap.push({i.second , i.first}) ;
                }
            }
            
            
        }
        
       while(!minHeap.empty()){
           answer.push_back(minHeap.top().second);
           minHeap.pop() ;
       }
        
        return answer ;
    }
};
Each element is inserted in minHeap - O(H-height od the tree) - O(K)
Time Complexity - O(N[HashMap] + NlogK(insertion of N elements) + klogK(deletetion on K elements) + N[adding in the answer vector] ) - O(NlogK)
Space Complecity - O(N[hashMap] + N[minHeap]) - O(N)
