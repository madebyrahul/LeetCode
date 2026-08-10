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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0,sum=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
             int val1 = (l1!=NULL) ? l1->val : 0;
             int val2 = (l2!=NULL) ? l2->val : 0;
             sum = val1 + val2 + carry;
             ListNode* newNode = new ListNode(sum%10);
             if(head==NULL){
                head = newNode;
                tail = newNode;
             }else{
                tail->next = newNode;
                tail = newNode;
             }
             carry = sum/10;
             if(l1!=NULL) l1 = l1->next;
             if(l2!=NULL) l2 = l2->next;
        }
        return head;
    }
};