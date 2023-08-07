class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     unordered_map<ListNode*,int>mp;

     while(headA!=NULL){
         ListNode* temp=headB;
         while(temp!=NULL){
             if(temp==headA){
                 return headA;
             }
             temp=temp->next;
         }
         headA=headA->next;
     }
     return NULL;
    }
};