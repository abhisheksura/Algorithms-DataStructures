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

/*
    LeetCode #142 - Linked List Beginning of Cycle
    https://leetcode.com/problems/linked-list-cycle-ii/
    Hare - Tortoise / 2 Pointer Technique
*/
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL or head->next == NULL) {
            return NULL;
        }
        ListNode *slow, *fast;
        
        slow = fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow) {
                break;
            }
        }

        if (slow != fast) {
            return NULL;
        }
        fast = head;
        while (1) {
            if (slow == fast) {
                return fast;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return NULL;
    }
};
