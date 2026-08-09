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

    void solve(ListNode* list1, ListNode* list2){
        ListNode* prev = list1;
        ListNode* nxt = prev->next;
        ListNode* temp = list2;
        ListNode* nxtTemp = NULL;
        while(nxt != NULL && temp != NULL){
            if((prev->val <= temp->val) && (nxt->val >= temp->val)){
                prev->next = temp;
                nxtTemp = temp->next;
                temp->next = nxt;
                prev = temp;
                temp = nxtTemp;
            }else{
                prev = nxt;
                nxt = nxt->next;
                if(nxt == NULL){
                    prev->next = temp;
                }
            }
        }
        if(nxt == NULL){
            prev->next = temp;
        }
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* head = NULL;
        if(list1->val <= list2->val){
            head = list1;
            solve(list1,list2);
        }else{
            head = list2;
           solve(list2,list1);
        }
        return head;
    }
};