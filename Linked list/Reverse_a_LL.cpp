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

    ListNode* reverseList(ListNode* head) {
        ListNode* newhead=reverse(head);
        return newhead;
    }
};