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

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt =  NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;
        ListNode* mid = getMid(head);
        mid->next = reverse(mid->next);
        ListNode* temp1 = head;
        ListNode* temp2 = mid->next;
        while(temp2 != NULL){
            if(temp1->val != temp2->val){
                return 0;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        mid->next = reverse(mid->next);
        return 1;
    }
};