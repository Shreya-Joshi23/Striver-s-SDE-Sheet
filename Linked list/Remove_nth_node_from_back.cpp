class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;

        ListNode* fast=dummyNode;
        ListNode* slow=dummyNode;

        while(n){
            fast=fast->next;
            n--;
        }

        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        if(slow!=dummyNode){
            slow->next=slow->next->next;
            return head;
        }else{                  //first node => n = last node
            slow=slow->next->next;
            return slow;
        }
        
    }
};