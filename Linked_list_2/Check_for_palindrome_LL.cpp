class Solution {
public:

     ListNode* reverse(ListNode* head){
    
        if(head==NULL || head->next==NULL) return head;

        ListNode* newhead=reverse(head->next);
        ListNode* headnext=head->next;
        headnext->next=head;
        head->next=NULL;

        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        
        //First find out the mid of the linked list
        //using slow and fast pointer approach

        ListNode* slow=head,*fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow->next=reverse(slow->next);
        ListNode* mid=slow->next;
        ListNode* start=head;

        while(mid!=NULL){
            if(start->val!=mid->val){
                return false;
            }
            mid=mid->next;
            start=start->next;
        }

        return true;

    }
};