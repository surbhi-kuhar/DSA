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

    ListNode*findMid(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode*reverseSecondHalf(ListNode*head){
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*next;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode*mid = findMid(head);

        ListNode*reversedTail = reverseSecondHalf(mid->next);

        mid->next=NULL;

        while(reversedTail!=NULL){
            ListNode*temp1 = head->next; 
            head->next = reversedTail;
            ListNode*temp2 = reversedTail->next; 
            reversedTail->next = temp1;
            head = temp1;
            reversedTail = temp2;
        }
    }
};