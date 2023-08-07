class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Tortoise and Hare Approach
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        
        return false;

    }
};