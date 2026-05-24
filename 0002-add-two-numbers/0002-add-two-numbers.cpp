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
        int carry = 0;

        ListNode*dummy = new ListNode(-1);
        ListNode*temp=dummy;

        while(l1!=NULL && l2!=NULL){
            int sum = l1->val+l2->val+carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);

            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }

        while(l1!=NULL){
            int sum = l1->val+carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);

            l1=l1->next;
            temp=temp->next;
        }

        while(l2!=NULL){
            int sum = l2->val+carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);

            l2=l2->next;
            temp=temp->next;
        }

        if(carry) temp->next=new ListNode(carry); 

        return dummy->next;
    }
};