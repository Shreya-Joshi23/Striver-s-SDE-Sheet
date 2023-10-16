class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* dummy=new ListNode(0);
    dummy->next=head;

    ListNode* pre=dummy;
    ListNode* cur=dummy;
    ListNode* nex=dummy;

    int cnt=0;

    while(cur->next!=NULL){
        cur=cur->next;
        cnt++;
    }

    if(head==NULL || k==1){
        return head; 
    }

    while(cnt>=k){
        cur=pre->next;
        nex=cur->next;
        for(int i=1;i<k;i++){
            cur->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=cur->next;
        }
        pre=cur;
        cnt-=k;
    }

    return dummy->next;

    }
};