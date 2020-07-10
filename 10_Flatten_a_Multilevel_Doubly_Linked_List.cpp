You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

 

Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:<image not inserted>
After flattening the multilevel linked list it becomes:<image not inserted>

Example 2:

Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation:

The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL

Example 3:

Input: head = []
Output: []

 

How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]

To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]

Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]

 

Constraints:

    Number of Nodes will not exceed 1000.
    1 <= Node.val <= 10^5

Solutions:

//Approach 1:
-> Approach is correct, idea is correct but i detail is missed out that the resultant node should be doubly linked list implies we will have ot remove the child points and make three pointer list to two pointers and this can be done while making child pointer NULL in such a way that they should be included as well as their should also be included in the final list 
-> this soulution works but do not give double pointers and just give three pointer solution
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    
public:
    Node* flatten(Node* head) {
       
        Node* answer = NULL ;
        Node* tail = NULL ;
        
        stack<Node*> lookup ;
        lookup.push(head) ;
        
        while(!lookup.empty()){
            
            Node* curr = lookup.top() ; 
            lookup.pop() ;
          
            if(curr->next != NULL) lookup.push(curr->next) ;
            if(curr->child != NULL) lookup.push(curr->child) ;
            
            if(answer == NULL){
                answer = curr ;
                tail = curr ;
            }
            else{
                tail->next = curr ;
                tail = tail->next ;
            }
            
        }
        return answer ;        
    }
};

//Approach 2
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head == NULL){ return NULL ;}
        
        Node* cur = head ;
        
        while(cur != NULL){
            
            if(cur->child != NULL){
                Node* next = cur->next ;
                Node* child = cur->child ;
                
                cur->next = child ;
                child->prev = cur ;
                cur->child = NULL ; 
                
                while(child->next != NULL){
                    child = child->next ;
                }
                child->next = next ;
                if(next != NULL) next->prev = child ;
            }
            else{
                cur = cur->next ;
            }
        }
        return head ;        
    }
};
