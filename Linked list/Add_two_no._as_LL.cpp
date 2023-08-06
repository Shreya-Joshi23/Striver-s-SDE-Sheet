class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry=0;
        int sum;
        ListNode newhead(0);
        ListNode* l3=&newhead;
        int x;

        while(carry||l1||l2){
            sum=carry+(l1?l1->val:0)+(l2?l2->val:0);
            l3->next=new ListNode(sum%10);
            l3=l3->next;
            carry=sum/10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }

        l3=&newhead;
        return l3->next;

    }
};