Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

Solutions:

//Approaches:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* start = NULL ;
        ListNode* tail = NULL ;
        
        while(head != NULL){
             
            if(head->val != val){
                ListNode* newnode = new ListNode(head->val) ;
                if(start == NULL){
                    start = newnode ;
                    tail = newnode ;
                }
                else{
                    tail->next = newnode ;
                    tail = tail->next ;
                }
            }
            
            head = head->next ;
        }
        return start;
    }
};

Time Complexity - O(n) 
Space COmplexity - O(n)

// Approach 2:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        //zero node
        if(head == NULL) return NULL ;
        
        ListNode* start = head ;
        
        //more than one node //middle and end node
        while(head->next != NULL){
             
            if(head->next->val == val ){
                head->next = head->next->next ;
            }
            else head = head->next ;
        }
        
        //one node
        if(start->val == val){
            start = start->next ;
        }

        return start;
    }
};

Time Complexity - O(n) 
Space Complexity - O(1)
