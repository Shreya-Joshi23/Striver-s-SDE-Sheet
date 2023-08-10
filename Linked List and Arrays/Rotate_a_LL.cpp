class Solution {
public:

    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL)return NULL;
        ListNode* nhead;
        ListNode* tail=head;
        int len=1;

        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }

        k=k%len;

        tail->next=head;

        for(int i=0;i<len-k;i++){
            tail=tail->next;
        }

        nhead=tail->next;
        tail->next=NULL;

        return nhead;

    }
};