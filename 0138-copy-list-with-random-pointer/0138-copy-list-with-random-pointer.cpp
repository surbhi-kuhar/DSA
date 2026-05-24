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
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL) return NULL;
        
        Node*headCopy = new Node(head->val);

        Node*temp1 = head, *temp2 = headCopy;

        unordered_map<Node*,Node*>pointers;
       
        while(temp1!=NULL){
            if(temp1->next!=NULL) temp2->next = new Node(temp1->next->val);
            else temp2->next = NULL;

            pointers[temp1] = temp2;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        temp1=head, temp2=headCopy;

        while(temp1!=NULL){
            if(temp1->random!=NULL) {
                temp2->random = pointers[temp1->random];
            }
            else temp2->random = NULL;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return headCopy;
    }
};