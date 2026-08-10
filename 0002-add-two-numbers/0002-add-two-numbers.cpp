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

    ListNode* insertAtHead(ListNode* &head,int digit){
        ListNode* temp = new ListNode(digit);
        if(head == NULL){
            head = temp;
        }else{
            temp->next = head;;
            head = temp;
        }
        return head;
    }

    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;
        int sum = 0;
        ListNode* head = NULL;
        while(l1 != NULL && l2 != NULL){
            sum = l1->val + l2->val + carry;
            int digit = sum%10;
            carry = sum/10;
            insertAtHead(head,digit);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            sum = carry + l1->val;
            int digit = sum%10;
            carry = sum/10;
            insertAtHead(head,digit);
            l1 = l1->next;
        }
        while(l2 != NULL){
            sum = carry + l2->val;
            int digit = sum%10;
            carry = sum/10;
            insertAtHead(head,digit);
            l2 = l2->next;
        }
        while(carry != 0){
            sum = carry;
            int digit = sum%10;
            insertAtHead(head,digit);
            carry = sum/10;
        }
        return head;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *ans = add(l1,l2);
        ans = reverse(ans);
        return ans;
    }
};