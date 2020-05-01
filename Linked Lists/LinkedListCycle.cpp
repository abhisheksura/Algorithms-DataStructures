/*
    LeetCode #141 - Linked List Cycle
    https://leetcode.com/problems/linked-list-cycle/
    
    Time Complexity - O(N)
    Space Complexity - O(1)
    Hare - Tortoise / 2 Pointer Technique  
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
