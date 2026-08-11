/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

void insertAtTail(Node* &head,Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* originalNode = head;
        while(originalNode != NULL){
            insertAtTail(cloneHead,cloneTail,originalNode->val);
            originalNode = originalNode->next;
        }
        Node* cloneNode = cloneHead;
        originalNode = head;
        Node* next = NULL;
        while(originalNode != NULL && cloneNode != NULL){
            next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next; 
        }
        Node* temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random ? temp->random->next : NULL;
            }
            temp = temp->next ? temp->next->next : NULL;
        }
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};