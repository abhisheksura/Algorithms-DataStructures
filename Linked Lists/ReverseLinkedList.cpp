/*
    LeetCode #206 - Reverse Linked List
    https://leetcode.com/problems/reverse-linked-list/
    
    Time Complexity - O(N)
    Hare - Tortoise / 2 Pointer Technique  
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *prev, *next;
        prev = next = NULL;
        
        while (head) {
            /* storing the next pointer in a variable */
            next = head->next;
            
            /* Reverse Operation */
            head->next = prev;
            
            /* Move the pointer to next element */
            prev = head;
            head = next;
        }
        return prev;
    }
};
